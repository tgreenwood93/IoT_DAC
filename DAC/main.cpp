#include "include/mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <string>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    // Set name for settings etc.
    QCoreApplication::setOrganizationName("TomG");
    QCoreApplication::setApplicationName("QT DAC");
    QCoreApplication::setApplicationVersion(APP_VERSION);

    // Show version if requested
    QCommandLineParser parser;

    // Create Qt application
    QApplication app(argc, argv);

    parser.addVersionOption();
    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addOptions({
        {"dev", "Enable developer mode for troubleshooting issues."},
        {"reset-credentials", "Allows providing new Spotify credentials."},
        {"paths", "Print paths for config file and cache."},
    });

    // TODO look at QCommandLineProcessor integration
    parser.process(app);

    if (parser.isSet("dev"))
    {
        qDebug() << "Dev Mode";
        //lib::developer_mode::enabled = true;
    }

    if (parser.isSet("paths"))
    {
        qDebug() << "Paths";
        //lib::developer_mode::enabled = true;
    }

    MainWindow w;

    // Show window and run application
    //if (!w.isValid())
    //{
    //    return 1;
    //}

    w.show();

    return app.exec();
}
