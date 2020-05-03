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
    QCommandLineOption hideWindowOption(QStringList() << "i" << "hide-window",
                                        "Hides the GUI");
    parser.addOption(hideWindowOption);
    parser.process(a);

    if(parser.isSet(showDebugOption)) {
        Settings::setDebug(true);
    }
    Settings::setConsoleOutput(parser.isSet(consoleOutputOption));
    MainWindow w;
    if(!parser.isSet(hideWindowOption)) {
        w.show();
    }
    return a.exec();
}
