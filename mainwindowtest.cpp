#include "mainwindowtest.h"
#include "ui_mainwindowtest.h"
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDebug>
MainWindowTest::MainWindowTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTest)
{
    ui->setupUi(this);
    QString fileName=QFileDialog::getOpenFileName(this,"Open Videos");
    QVideoWidget *videoWidget=new QVideoWidget();
    this->setCentralWidget(videoWidget);
    QMediaPlayer *player=new QMediaPlayer;
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl::fromLocalFile(fileName));

    player->play();

    qDebug()<<fileName;
}

MainWindowTest::~MainWindowTest()
{
    delete ui;
}
