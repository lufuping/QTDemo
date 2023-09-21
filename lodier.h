#ifndef LODIER_H
#define LODIER_H

#include <QObject>

class lodier : public QObject
{
    Q_OBJECT
public:
    explicit lodier(QObject *parent = nullptr);

signals:

public slots:
    void fight();
    // 槽重载
    void fight(QString);
    // 新建逃跑槽函数
    void escape();
};

#endif // LODIER_H
