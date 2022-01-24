#include <QApplication>
#include <QLocale>
#include <string>
#include <QCommandLineParser>

#include "include/lib/crash/crashhandler.h"
#include "include/lib/developermode.h"
#include "include/lib/log.h"
#include "include/mainwindow.h"

#include "include/qt/qtpaths.h"


int main(int argc, char *argv[])
{
    // Set name for settings etc.
    QCoreApplication::setOrganizationName("TomG");
    QCoreApplication::setApplicationName("QT DAC");
    QCoreApplication::setApplicationVersion(APP_VERSION);

    // set paths for storing settings and crash files
    QtPaths paths(nullptr);
    lib::settings settings(paths);

    // Show version if requested
    QCommandLineParser parser;

    lib::crash_handler::init();

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

    parser.process(app);

    if (parser.isSet("dev")) {
        lib::log::info("Developer Mode Enabled");
        lib::developer_mode::enabled = true;
    }

    if (parser.isSet("paths")) {
        lib::log::info("Config: {}", paths.config_file());
        lib::log::info("Cache:  {}", paths.cache());
        return 0;
    }

    MainWindow w(nullptr, settings, paths);

    // Show window and run application
    if (!w.isValid())
        return 1;

    w.show();

    return app.exec();
}
