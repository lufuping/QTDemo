#include "widget01.h"
#include "ui_widget01.h"
#include "QPushButton"
#include"mywidget.h"
#include"lodier.h"
#include<QDebug>
#include<QString>
#include"register.h"
#include "ui_register.h"
#include<QMessageBox>
#include"data.h"
Widget01::Widget01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget01)
{
    ui->setupUi(this);
    r_ui= new Register();
    v_ui=new ViewingFilm();
    player_ui=new PlayVideo();
    init();
    // 建立回退信号的连接
    connect(r_ui,&Register::qutUi,this,&Widget01::quitShowUi);
    // 创建打开视频的信号连接
    connect(v_ui,&ViewingFilm::isQut,this,&Widget01::openVideoWin);
#if 0
    // 创建一个按钮，按下按钮窗口关闭
    QPushButton *button1= new QPushButton("退出",this);
    button1->setGeometry(50,50,200,100);
    QPushButton *button2= new QPushButton("退出2",this);
    button2->setGeometry(500,50,200,100);
    // 创建连接
    //connect(button1,SIGNAL(clicked(bool)),this,SLOT(close())); // qt4
    connect(button1,&QPushButton::clicked,button2,&QPushButton::clicked); // qt5

    // 信号传递信号
    connect(button2,&QPushButton::clicked,this,&Widget01::close);
#endif
#if 0
    // 自定义信号和槽的测试
    // 实例化信号和槽
    mywidget *s=  new mywidget();
    lodier *l= new lodier();
    //创建连接
    // 信号指针
    void (mywidget::*go)()= &mywidget::go;
    void (mywidget::*go1)(QString)= &mywidget::go;
    // 槽指针error-请先设置百度Appid,申请链接看软件介绍(免费的)
    void (lodier::*f)()= &lodier::fight;
    void (lodier::*f1)(QString)= &lodier::fight;
    void(lodier::*escape)()=&lodier::escape;
    // 一个信号连接多个槽函数，QT5执行顺序按照创建的顺序进行
    connect(s,go,l,f);

    connect(s,go,l,escape);

    connect(s,go1,l,f1);
    // 尝试QT4连接
    //      connect(s,SIGNAL(go()),l,SLOT(fight()));
    //      connect(s,SIGNAL(go(QString)),l,SLOT(fight(QString)));

    // 发送信号
    // 断开连接
    s->disconnect(s,go,l,escape);
    s->go();
    emit s->go("冲左");


#endif
}
//QPushButton *button1= new QPushButton("这是一个按钮",nullptr);
// 设置按钮位置和大小
// *button1 ->setGeometry(50, 50, 200, 100);
Widget01::~Widget01()
{
    delete ui;
}

// 处理登录逻辑
void Widget01::on_btn_login_clicked()
{
    // todo: 设计一个简单的模拟数据库
    QString acc=ui->account_L->text();
    QString pas=ui->password_L->text();

    int res=isHave(acc,pas);
    if(res==0){

        // QMessageBox::information(this,"成功","登录成功");
        // todo: 转跳到系统页面
        // 1. 实现跳转
        this->hide();
        v_ui->show();
    }else if(res==1){
        //qDebug()<<"账号密码错误";
        QMessageBox::critical(this,"错误","用户不存在");
    }
    else if(res==2){
        QMessageBox::critical(this,"错误","密码错误");
    }
}
// 处理注册逻辑
void Widget01::on_btn_register_clicked()
{
    this->hide();
    r_ui->setWindowTitle("注册");
    r_ui->show();
}
// 处理注册成功之后的逻辑
void Widget01::quitShowUi(QString acc,QString pas)
{
    // 询问是否要记住密码
    int result = QMessageBox::question(this, "询问", "是否记住账号密码",QMessageBox::Yes | QMessageBox::No);
    r_ui->hide();
    this->show();
    if(result==QMessageBox::Yes){
        ui->account_L->setText(acc);
        ui->password_L->setText(pas);
    }

}

void Widget01::openVideoWin()
{
    //this->show();
    player_ui->show();

}
