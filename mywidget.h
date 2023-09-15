#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>

class mywidget : public QObject
{
    Q_OBJECT
public:
    explicit mywidget(QObject *parent = nullptr);

signals:

};

#endif // MYWIDGET_H
