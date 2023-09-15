#include "widget01.h"
#include "ui_widget01.h"

Widget01::Widget01(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget01)
{
    ui->setupUi(this);
}

Widget01::~Widget01()
{
    delete ui;
}

