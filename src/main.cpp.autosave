#include <QtWidgets/QApplication>
#include <QCommandLineParser>
#include "ui/mainwindow.h"

#include <QTextStream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Projectgus");
    QCoreApplication::setOrganizationDomain("projectgus.com");
    QCoreApplication::setApplicationName("Hairless MIDI Serial Bridge");
    QCoreApplication::setApplicationVersion(QString::fromUtf8(VERSION));

    QCommandLineParser parser;
    parser.setApplicationDescription("Sends and receives MIDI events over a serial device.");
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption showDebugOption(QStringList() << "d" << "debug",
                                       QCoreApplication::translate("main", "Show debug MIDI messages"));
    parser.addOption(showDebugOption);
    parser.process(a);

//    QTextStream out(stdout);
//    out << QString("Hello, World!") << endl;


    MainWindow w;

    if(parser.isSet(showDebugOption)) {
        w.setDebugFromCommandLine(true);
    }

    w.show();
    return a.exec();
}
