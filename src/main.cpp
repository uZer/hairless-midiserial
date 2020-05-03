#include <QtWidgets/QApplication>
#include <QCommandLineParser>
#include "ui/mainwindow.h"

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
                                       "Show debug MIDI messages");
    parser.addOption(showDebugOption);
    QCommandLineOption consoleOutputOption(QStringList() << "c" << "console-debug",
                                       "Output debug messages to the console");
    parser.addOption(consoleOutputOption);
    parser.process(a);


    MainWindow w;
    if(parser.isSet(showDebugOption)) {
        w.setDebugFromCommandLine(true);
    }
    if(parser.isSet(consoleOutputOption)) {
        w.setConsoleDebugFromCommandLine(true);
    }
    w.show();
    return a.exec();
}
