#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QGraphicsScene>
//#include <QNetworkAccessManager>
#include "imagewidget.h"
#include "http_client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void AlbumArt1_MenuButton_Clicked();

    MainWindow(QWidget *parent = nullptr);
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
    //lib::http_client *httpClient = nullptr;
    //spt::Spotify *spotify = nullptr;

    // Non-Widget Qt
    //QNetworkAccessManager *network = nullptr;

};
#endif // MAINWINDOW_H
