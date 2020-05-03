#include <QtWidgets/QApplication>
#include <QCommandLineParser>
#include "ui/mainwindow.h"
#include "Settings.h"

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
    QCommandLineOption consoleOutputOption(QStringList() << "c" << "console-output",
                                       "Output messages to the console");
    parser.addOption(consoleOutputOption);
    parser.process(a);

    if(parser.isSet(showDebugOption)) {
        Settings::setDebug(true);
    }
    if(parser.isSet(consoleOutputOption)) {
        Settings::setConsoleOutput(true);
    } else {
        Settings::setConsoleOutput(false);
    }

    MainWindow w;

    w.show();
    return a.exec();
}
