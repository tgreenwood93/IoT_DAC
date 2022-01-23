#include "include/mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsDropShadowEffect>
#include <QString>


extern "C" {
#include "include/network.h"
}


// TODO make enums for all menus
enum {
    e_MAIN_DISPLAY_1 = 0,
    e_MAIN_DISPLAY_AA = 2
};

int main_display = e_MAIN_DISPLAY_1;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer.start();

    //this->setStyleSheet("background-color: dark-gray;");
    //this->setStyleSheet("text-color: white;");

    // Home1 menu
    connect(ui->Menu, &QPushButton::clicked, this, &MainWindow::Home1_MenuButton_Clicked);

    // Settings1 menu
    connect(ui->Menu_Exit, &QPushButton::clicked, this, &MainWindow::Settings1_MenuButton_Clicked);
    connect(ui->AlbumFullToggle, &QRadioButton::toggled, this, &MainWindow::Settings1_BigAlbumMenu_Toggle);
    connect(ui->NetworkMenuButton, &QPushButton::clicked, this, &MainWindow::Settings1_NetworkMenu_Clicked);

    // network1 menu
    connect(ui->Menu_3, &QPushButton::clicked, this, &MainWindow::Network1_MenuButton_Clicked);
    connect(ui->BA_Exit_2, &QPushButton::clicked, this, &MainWindow::Network1_ExitButton_Clicked);

    // AA menu
    connect(ui->Menu_2, &QPushButton::clicked, this, &MainWindow::AlbumArt1_MenuButton_Clicked);

    ui->stackedWidget->setCurrentIndex(main_display);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setXOffset(5);
    effect->setYOffset(5);
    effect->setColor(Qt::gray);

    QPixmap pix(imgFilename);
    ui->AlbumArt->setPixmap(pix.scaledToHeight(400));
    ui->AlbumArt->setGraphicsEffect(effect);

    // Set Spotify
    //splash.showMessage("Connecting...");
    //httpClient = new lib::qt::http_client(this);
    //spotify = new spt::Spotify(settings, *httpClient, this);
    //network = new QNetworkAccessManager(this);

    // REVIEW might need to move this
    stateValid = true;

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AlbumArt1_MenuButton_Clicked()
{
    qDebug() << "AA1 Menu button was pressed!";
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::Home1_MenuButton_Clicked()
{
    qDebug() << "Home1 Menu button was pressed!";
    ui->stackedWidget->setCurrentIndex(1);


}


void MainWindow::Settings1_MenuButton_Clicked()
{
    qDebug() << "Settings1 Menu Button was pressed!";
    ui->stackedWidget->setCurrentIndex(main_display);
}

void MainWindow::Settings1_BigAlbumMenu_Toggle()
{
    if (ui->AlbumFullToggle->isChecked())
    {
        qDebug() << "Big Album Art Mode Selected!";
        main_display = e_MAIN_DISPLAY_AA;
    }
    else
    {
        qDebug() << "Big Album Art Mode Cleared!";
        main_display = e_MAIN_DISPLAY_1;
    }
}


void MainWindow::Settings1_NetworkMenu_Clicked()
{
    qDebug() << "Settings1 Netowrk Menu Button was pressed!";

    // TODO this can be handled better...
    network_info_t* network_list;

    int num_nets = getNetworks(&network_list);

    qDebug() << "Num networks found: " << num_nets;


    // TODO make a function that handles parsing WIFI/ETH/LO/ect...
    // TODO handle no NULL networks
    QString ethernet_ip = ("IP: ");
    QString ethernet_mask = ("Mask: ");
    QString ethernet_gateway = ("Gateway: ");
    QString ethernet_interface = ("Interface: ");

    ethernet_ip.append(network_list[1].addr);
    ethernet_mask.append(network_list[1].netmask);
    ethernet_gateway.append(network_list[1].network);
    ethernet_interface.append("Ethernet");


    ui->label->setText(ethernet_ip);
    ui->label_2->setText(ethernet_mask);
    ui->label_3->setText(ethernet_gateway);
    ui->label_4->setText(ethernet_interface);

    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::Network1_MenuButton_Clicked()
{
    qDebug() << "Network1 MenuButton was pressed!";
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::Network1_ExitButton_Clicked()
{
    qDebug() << "Network1 ExitButton was pressed!";
    ui->stackedWidget->setCurrentIndex(main_display);
}


void MainWindow::update_picture()
{
    if (imgFilename.isEmpty())
        return;

    //albumArtwork->load(imgFilename);

    //QPixmap pix("/home/tom/projects/Qt/DAC/resources/img.jpg");
    //ui->AlbumArt->setPixmap(pix);


    //qDebug() << imgFilename;
    //QImage image(imgFilename);
    //static QPixmap pix( imgFilename );

    //QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    //QGraphicsScene* scene = new QGraphicsScene();

    //scene->setScene(ui->AlbumArt->rect());
    //ui->AlbumArt->setSceneRect(0, 0, 500, 500);
    //static QImage qImg(pix.toImage().convertToFormat(QImage::Format_ARGB32_Premultiplied));
    //static auto pixImg = QPixmap::fromImage(qImg);

    //QGraphicsPixmapItem item(QPixmap("~/Desktop/img.jpg"));
    //item->setOffset(-250,-250);
    //item->setPos(0,0);

    //scene->setSceneRect(0, 0, 500, 500);
    //qDebug() << item->
    //ui->AlbumArt->

    //scene->addItem(&item);
    //scene->addItem(item);

    //qDebug() << "W" << scene->width() << "H" << scene->height();

    //scene->update();
    //ui->AlbumArt->setFixedSize(600, 600);
    //ui->AlbumArt->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    //scene->addText("Hello");
    //scene->show();
    //ui->AlbumArt->show();

}


auto MainWindow::isValid() const -> bool
{
    return stateValid;
}


