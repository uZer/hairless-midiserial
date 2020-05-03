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

    QCommandLineOption serialPortOption(QStringList() << "s" << "serial",
                                        "Specify the name of the serial device to use", "serial");
    parser.addOption(serialPortOption);
    parser.process(a);

    if(parser.isSet(showDebugOption)) {
        Settings::setDebug(true);
    }
    Settings::setConsoleOutput(parser.isSet(consoleOutputOption));
    if(parser.isSet(serialPortOption)) {
        Settings::setLastSerialPort(parser.value(serialPortOption));
    }
    MainWindow w;
    if(!parser.isSet(hideWindowOption)) {
        w.show();
    }
    return a.exec();
}
