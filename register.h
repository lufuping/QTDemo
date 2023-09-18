#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include<QString>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT


public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
signals:
    // 退出注册页面并返回登录界面
    void qutUi(QString acc,QString pas);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *regisetrUi;
};

#endif // REGISTER_H
