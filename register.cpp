#include "register.h"
#include "ui_register.h"
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include"data.h"
Register::Register(QWidget *parent) :
    QWidget(parent),
    regisetrUi(new Ui::Register)
{
    regisetrUi->setupUi(this);


}

Register::~Register()
{
    delete regisetrUi;
}
void Register::on_pushButton_clicked()
{
    // 输入账号
    QString acc=regisetrUi->account_R->text();
    // 输入的密码
    QString pas= regisetrUi->password_R->text();
    // 确认密码
    QString rPas=regisetrUi->confirmPassword->text();
    if(acc!=""&&pas!=""&&rPas!=""){
        if(pas==rPas){
            add(acc,pas);
            QMessageBox::information(this,"成功","注册成功");
            // 发送回退信号
            this->qutUi(acc,pas);
            // 清空注册内容
            regisetrUi->account_R->clear();
            regisetrUi->password_R->clear();
            regisetrUi->confirmPassword->clear();
        }else{
            QMessageBox::critical(this,"错误","两次输入的密码不一致");
        }
    }else{
        QMessageBox::critical(this,"错误","账号密码不能为空");
    }
}
