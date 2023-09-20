#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_btnMyPlayer_clicked()
{
    this->openMyPlayer();
}

void Menu::on_btnMyAI_clicked()
{
    this->openMyAI();
}
