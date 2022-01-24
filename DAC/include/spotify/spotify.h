#pragma once

//#include "dialog/deviceselectdialog.h"
#include "include/lib/spotify/followtype.h"
#include "include/qt/httpclient.h"
#include "include/lib/settings.h"
#include "include/lib/spotify/api.h"
#include "include/lib/spotify/artist.h"
#include "include/lib/spotify/device.h"
#include "include/lib/spotify/playback.h"
#include "include/lib/spotify/playlist.h"
#include "include/lib/spotify/searchresults.h"
#include "include/lib/spotify/user.h"
//#include "include/lib/strings.h"
#include "thirdparty/json/single_include/nlohmann/json.hpp"
#include <QCoreApplication>
#include <QDateTime>
#include <QDesktopServices>
#include <QInputDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcessEnvironment>
#include <QSettings>
#include <QString>
#include <QVector>
#include <QtNetwork>
#include <QMessageBox>

namespace spt
{
    class Spotify: public QObject, public lib::spt::api
    {
        Q_OBJECT

        public:
            explicit Spotify(lib::settings &settings,
                const lib::http_client &httpClient, QObject *parent = nullptr);

            auto tryRefresh() -> bool;

        private:
            void select_device(const std::vector<lib::spt::device> &devices,
                lib::callback<lib::spt::device> &callback) override;
    };
}
