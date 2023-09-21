#include"data.h"
#include"widget01.h"
#include<QMessageBox>
QMap<QString,QString> data;
void init(){
    data.insert("xiaolu","1");
}
void add(QString acc, QString pas)
{
    data.insert(acc,pas);
}

int isHave(QString acc, QString pas)
{
    bool b= data.contains(acc);
    if(!b){
        return 1;
    }
    QString p=data.value(acc);
    if(p!=pas){
        return 2;
    }
    return 0;
}
