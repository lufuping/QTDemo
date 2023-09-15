#ifndef WIDGET01_H
#define WIDGET01_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget01; }
QT_END_NAMESPACE

class Widget01 : public QWidget
{
    Q_OBJECT

public:
    Widget01(QWidget *parent = nullptr);
    ~Widget01();

private:
    Ui::Widget01 *ui;
};
#endif // WIDGET01_H
