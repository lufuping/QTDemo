#ifndef LODIER_H
#define LODIER_H

#include <QObject>

class lodier : public QObject
{
    Q_OBJECT
public:
    explicit lodier(QObject *parent = nullptr);

signals:

};

#endif // LODIER_H
