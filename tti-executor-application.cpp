#include "tti-executor-application.h"

#include "../TTI/Common/DllManager/dllmanager.h"
#include "../TTI/Common/RunManager/runmanager.h"

#include <QFileInfo>
#include <QTextStream>

TTIExecutorApplication::TTIExecutorApplication(int &argc, char **argv) : QCoreApplication(argc,argv)
{
    DLLManager::Init();
    RunManager::Init();

    for(int i = 2; i < arguments().length(); i += 2)
    {
        if(QFileInfo(arguments().at(i-1)).exists())
        {
            QString comment = arguments().at(i);

            if(QFileInfo(comment).exists())
            {
                QFile f(comment);
                if (f.open(QFile::ReadOnly | QFile::Text))
                {
                    QTextStream in(&f);
                    comment = in.readAll();
                    f.close();
                }
            }

            RunManager::AddPlan(arguments().at(i-1), comment);

            QTextStream out(stdout);
            out << "Test plan " << arguments().at(i-1) << endl;
            out << " was queued with description \"" << comment << "\"" << endl << endl;
        }
    }

    connect(RunManager::Handle, &RunManager::logChanged, this, &TTIExecutorApplication::onLogChanged);
    connect(RunManager::Handle, &RunManager::testStarted, this, &TTIExecutorApplication::onTestStarted);
    connect(RunManager::Handle, &RunManager::testFinished, this, &TTIExecutorApplication::onTestFinished);
    connect(RunManager::Handle, &RunManager::testCaseStarted, this, &TTIExecutorApplication::onTestCaseStarted);
    connect(RunManager::Handle, &RunManager::testCaseFinished, this, &TTIExecutorApplication::onTestCaseFinished);
    connect(RunManager::Handle, &RunManager::planStarted, this, &TTIExecutorApplication::onPlanStarted);
    connect(RunManager::Handle, &RunManager::planFinished, this, &TTIExecutorApplication::onPlanFinished);
    connect(RunManager::Handle, &RunManager::allFinished, this, &TTIExecutorApplication::onAllFinished);
}

TTIExecutorApplication::~TTIExecutorApplication()
{
    DLLManager::FreeResources();
    RunManager::FreeResources();
}

void TTIExecutorApplication::StartQueue()
{
    RunManager::Start(0);
}

void TTIExecutorApplication::onLogChanged(int planInd, int newLogLine)
{
    PlanQueueItem *plan = RunManager::GetPlan(planInd);

    for(int i = newLogLine; i < plan->log.length(); i++)
    {
        QTextStream out(stdout);
        out << plan->log.at(i) << endl;
    }
}

void TTIExecutorApplication::onTestStarted(int planInd)
{
}

void TTIExecutorApplication::onTestFinished(int planInd)
{
}

void TTIExecutorApplication::onTestCaseStarted(int planInd)
{
}

void TTIExecutorApplication::onTestCaseFinished(int planInd)
{
}

void TTIExecutorApplication::onPlanStarted(int planInd)
{
    QTextStream out(stdout);
    PlanQueueItem *plan = RunManager::GetPlan(planInd);
    out << endl << "Plan " << plan->fullFileName << endl;
}

void TTIExecutorApplication::onPlanFinished(int planInd)
{
}

void TTIExecutorApplication::onAllFinished()
{
    exit(0);
}
