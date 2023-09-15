#include "lodier.h"
#include<QDebug>
lodier::lodier(QObject *parent) : QObject(parent)
{

}
// 实现槽函数
void lodier::fight(){
    qDebug()<<"该杀敌了";
}
// 实现槽重载
void lodier::fight(QString){
    qDebug()<<"冲锋左翼";
}

void lodier::escape()
{
    qDebug()<<"我害怕，我要逃跑";
}
