#include "viewingfilm.h"
#include "ui_viewingfilm.h"
#include<QDebug>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVBoxLayout>
#include <QFileDialog>
#include<QMovie>
ViewingFilm::ViewingFilm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewingFilm)
{
    ui->setupUi(this);
    this->setWindowTitle("播放器");
    ui->play->setCheckable(true);
}

ViewingFilm::~ViewingFilm()
{
    delete ui;
}

//void ViewingFilm::on_pushButton_clicked()
//{

//}

void ViewingFilm::on_play_clicked(bool flag)
{
#if 0
    if(flag==true){
        //        QPixmap picture(":/game");
        //        ui->displayM->setPixmap(picture);
        // 视频的URl
        QString url="https://www.bilibili.com/video/BV1Ky4y1F7Rc/?spm_id_from=333.1007.tianma.2-1-4.click&vd_source=7244cdd8c7d347776bc576f7afef7c8b";
        // 创建视频输出窗口
        QVideoWidget *v= new QVideoWidget(this);
        v->setFixedSize(640,500);
        //this->setContextMenuPolicy(v);
        // 尝试引入视频解析器
        _player=new QMediaPlayer();
        _player->setMedia(QMediaContent(QUrl(url)));
        // 将 QWidget 的 createWindowContainer 函数返回值（即窗口容器）设置为 QLabel 的父对象，并添加到布局或界面上。
        //QWidget *videoWidget = QWidget::createWindowContainer(_player, ui->displayM);
        //this->addWidget(videoWidget); // 假设有名为 videoLayout 的布局
        _player->setVideoOutput(v);
    }

    else
    {
        ui->displayM->clear();
    }
#endif
#if 1
    if(flag==true&&m!=nullptr){

        // 开始
        m->start();
        // 设置像素
        ui->displayM->setMovie(m);
        // 将按钮标签更改为清空
        ui->play->setText("清空");
    }

    else
    {
        ui->displayM->clear();
        // 将按钮标签更改为播放
        ui->play->setText("播放");
    }
#endif
}

void ViewingFilm::on_next_clicked()
{
    // 最小化当前窗口
    this->hide();
    // 打开视频播放窗口
    // 发送打开视频的信号
    this->isQut();
}

void ViewingFilm::on_btnChoose_clicked()
{
    QString playFilePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                             "/",
                                                             tr("Images (*.png *.xpm *.jpg *.jpeg *.gif *.bmp *.svg *.tif *.tiff)"));
            m= new QMovie(playFilePath);
}
