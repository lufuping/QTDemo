#ifndef WIDGET01_H
#define WIDGET01_H

#include <QWidget>
#include"register.h"
#include"viewingfilm.h"
#include"playvideo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget01; }
QT_END_NAMESPACE

class Widget01 : public QWidget
{
    Q_OBJECT

public:
    Widget01(QWidget *parent = nullptr);
    ~Widget01();

private slots:
    void on_btn_login_clicked();

    void on_btn_register_clicked();
    // 实现关闭注册窗口并展开登录窗口
    // 2. 将注册的账号和密码设置到登录槽中
    void quitShowUi(QString acc,QString pas);
    // 处理视频播放器的打开
    void openVideoWin();

private:
    Ui::Widget01 *ui;
    Register *r_ui;
    ViewingFilm *v_ui;
    PlayVideo *player_ui;
};
#endif // WIDGET01_H
