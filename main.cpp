#include "tti-executor-application.h"

#include <QTextStream>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        TTIExecutorApplication a(argc, argv);
        a.StartQueue();
        return a.exec();
    }
    else
    {
        QTextStream out(stdout);
        out << "Execute several testing plans in console mode." << endl << endl;
        out << "TTIE.EXE [plan description] ..." << endl << endl;
        out << "plan\t\tSpecifies the full file name of testing plan to be queued." << endl;
        out << "description\tSpecifies the description to be saved in run description." << endl;
        return 0;
    }
}
