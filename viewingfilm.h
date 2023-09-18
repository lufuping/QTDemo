#ifndef VIEWINGFILM_H
#define VIEWINGFILM_H

#include <QWidget>
#include<QMediaPlayer>
namespace Ui {
class ViewingFilm;
}

class ViewingFilm : public QWidget
{
    Q_OBJECT

public:
    explicit ViewingFilm(QWidget *parent = nullptr);
    ~ViewingFilm();
signals:
    // 打开视频播放器的信号
    void isQut();
private slots:
    //void on_pushButton_clicked();
    //  处理播放相关
    void on_play_clicked(bool flag);

    void on_next_clicked();


private:
    Ui::ViewingFilm *ui;
    QMediaPlayer *_player;
};

#endif // VIEWINGFILM_H
