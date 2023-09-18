#ifndef DATA_H
#define DATA_H
#include<QMap>
#include<QString>
// 实现存储注册成功的用户
void add(QString acc,QString pas);
// 实现登录时查找，返回0 正常   1 账号不存在   2 密码不正确
int isHave(QString acc,QString pas);
// 初始化方法
void init();
#endif // DATA_H
