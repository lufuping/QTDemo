#include "licenseplaterecognition.h"
#include "ui_licenseplaterecognition.h"
#include"ocr.h"
#include<iostream>
LicensePlateRecognition::LicensePlateRecognition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LicensePlateRecognition)
{
    ui->setupUi(this);
     ui->btnCho->setCheckable(true);
}

LicensePlateRecognition::~LicensePlateRecognition()
{
    delete ui;
}

void LicensePlateRecognition::on_btnCho_clicked(bool flag)
{
    if(flag==true){

            // 处理点击之后的逻辑内容
            // 跳转到硬盘目录，找到想要的图片
            // 拿到文件路径
            QString filePath= QFileDialog::getOpenFileName(this,"open file","/","all(*.*)");
            // 将图片的信息设置到inPath中
            ui->inPath->setText(filePath.toUtf8());
            // 将图片显示到lCar中
            QPixmap img(filePath);
            ui->lCar->setPixmap(img);
            // 调用OpenCV车牌识别接口,并检索车牌号，显示到inNumber中
            aip::Ocr client(app_id, api_key, secret_key);
            Json::Value result;

            std::string image;
            aip::get_file_content(filePath.toStdString().data(), &image);

            // 调用车牌识别
            result = client.license_plate(image, aip::null);

            // 如果有可选参数
            std::map<std::string, std::string> options;
            options["multi_detect"] = "true";

            // 带参数调用车牌识别
            result = client.license_plate(image, options);
            // 拿到车牌号
            num=QString::fromStdString(result["words_result"][0]["number"].asString());

            ui->inNumber->setText(num);

        }else{
            // 处理第二次点击之后的逻辑
            ui->inPath->clear();
            ui->lCar->clear();
        }
}
