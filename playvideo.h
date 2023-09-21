#ifndef PLAYVIDEO_H
#define PLAYVIDEO_H

#include <QWidget>
#include<QtMultimedia/QtMultimedia>
#include<QtMultimediaWidgets/QVideoWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QSslConfiguration>
namespace Ui {
class PlayVideo;
}

class PlayVideo : public QWidget
{
    Q_OBJECT

public:
    explicit PlayVideo(QWidget *parent = nullptr);
    ~PlayVideo();

private slots:
    void on_testVideo_clicked(bool flag);

    void on_btnChoseVideo_clicked();

private:
    Ui::PlayVideo *ui;
    // 播放器的窗口
    QVideoWidget *videoWidget;
    // 播放器
    QMediaPlayer *player;
    // 播放标签
    //int flag=0;
};

#endif // PLAYVIDEO_H
