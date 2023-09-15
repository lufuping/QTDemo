#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
// 自定义信号和曹  继承 QObject  宏Q_OBJECT
class mywidget : public QObject
{
    Q_OBJECT
public:
    explicit mywidget(QObject *parent = nullptr);

signals:
  // 自定义信号 冲冲冲
    void go();
  // 信号的重载
    void go(QString);
};

#endif // MYWIDGET_H
