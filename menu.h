#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

signals:
    // 给主窗口发送打开播放器的信号
    void openMyPlayer();
    // 给主窗口发送打开AI的信号
    void openMyAI();
    // 其他


private slots:
    // 处理跳转到播放器页面
    void on_btnMyPlayer_clicked();
    // 处理跳转到AI实例
    void on_btnMyAI_clicked();



private:
    Ui::Menu *ui;
};

#endif // MENU_H
