#ifndef TTIEXECUTORAPPLICATION_H
#define TTIEXECUTORAPPLICATION_H

#include <QCoreApplication>
#include <QTimer>

class TTIExecutorApplication : public QCoreApplication
{
public:
    TTIExecutorApplication(int &argc, char **argv);
    ~TTIExecutorApplication();

    void StartQueue();

private:
    QTimer sharedMemoryWatcher;

private slots:
    void onLogChanged(int planInd, int newLogLine);
    void onTestStarted(int planInd);
    void onTestFinished(int planInd);
    void onTestCaseStarted(int planInd);
    void onTestCaseFinished(int planInd);
    void onPlanStarted(int planInd);
    void onPlanFinished(int planInd);
    void onAllFinished();

};

#endif // TTIEXECUTORAPPLICATION_H
