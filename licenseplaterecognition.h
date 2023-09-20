#ifndef LICENSEPLATERECOGNITION_H
#define LICENSEPLATERECOGNITION_H

#include <QWidget>
#include<QFileDialog>
//#include<iostream>
namespace Ui {
class LicensePlateRecognition;
}

class LicensePlateRecognition : public QWidget
{
    Q_OBJECT

public:
    explicit LicensePlateRecognition(QWidget *parent = nullptr);
    ~LicensePlateRecognition();

private slots:
    // 打开浏览本地目录
    void on_btnCho_clicked(bool flag);

private:
    Ui::LicensePlateRecognition *ui;
    QFileDialog *file;
    QString num;
    // 设置APPID/AK/SK
    std::string app_id = "39539330";
    std::string api_key = "TiKgGlrWGqhDp8gT3QkVxcPg";
    std::string secret_key = "kTnGVS0YZLuGn4LGRPh5ryPvteAdhEa0";
};

#endif // LICENSEPLATERECOGNITION_H
