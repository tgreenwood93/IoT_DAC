#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QGraphicsScene>
//#include <QNetworkAccessManager>
#include "include/imagewidget.h"
#include "include/http_client.h"
#include "include/lib/crash/crashhandler.h"
#include "include/qt/httpclient.h"
//#include "include/httpclient.h"
#include "spotify/spotify.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void AlbumArt1_MenuButton_Clicked();

    MainWindow(QWidget *parent, lib::settings &settings, lib::paths &paths);
    //MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Home1_MenuButton_Clicked();

    bool isValid() const;

    //network1 funcs
    void Network1_MenuButton_Clicked();
    void Network1_ExitButton_Clicked();

    void Settings1_MenuButton_Clicked();
    void Settings1_BigAlbumMenu_Toggle();
    void Settings1_NetworkMenu_Clicked();

    void update_picture();

private:
    Ui::MainWindow *ui;

    QElapsedTimer timer;

    QString imgFilename = "/home/tom/projects/Qt/DAC/resources/blank.png";

    QGraphicsScene* scene;

    ImageWidget* albumArtwork;

    bool stateValid = true;

    // lib
    lib::settings &settings;
    lib::paths &paths;
    lib::http_client *httpClient = nullptr;
    lib::json_cache cache;
    spt::Spotify *spotify = nullptr;

    // Non-Widget Qt
    QNetworkAccessManager *network = nullptr;

};
#endif // MAINWINDOW_H
