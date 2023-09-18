#include "playvideo.h"
#include "ui_playvideo.h"

PlayVideo::PlayVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayVideo)
{
    ui->setupUi(this);
    this->setWindowTitle("视频播放器");
    ui->testVideo->setCheckable(true);
    // 实例化窗口
    videoWidget=new QVideoWidget(this);
    videoWidget->resize(400,300);
    // 实例化播放器
    player=new QMediaPlayer(this);
    // todo: 配置ssl，支持https协议
//    QMediaContent mediaContent(QUrl("https://example.com/your_file.mp4"));
//    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
//    sslConfig.setProtocol(QSsl::TlsV1_2); // 设置所需TLS版本（可选）
//    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone); // 可以选择是否验证对等方证书
//    auto networkAccessManager = new QNetworkAccessManager(this);
//    networkAccessManager->connectToHostEncrypted(mediaContent.canonicalUrl().host(), 443, sslConfig);
//    player->setPlaylist(networkReply);

//    // 将自定义网络访问管理器分配给播放器实例，以便处理HTTPS请求。
//    player->setNetworkAccessProxy(networkReply);
    // 设置到窗口播放
    player->setVideoOutput(videoWidget);
    // 设置播放的内容
    player->setMedia(QMediaContent(QUrl::fromLocalFile("E:/百度网盘下载/在线教育项目/1-阿里云上传测试视频/test_video.mp4")));
    // 设置URL
    //QString url="https://www.bilibili.com/video/BV1Ky4y1F7Rc/?spm_id_from=333.1007.tianma.2-1-4.click&vd_source=7244cdd8c7d347776bc576f7afef7c8b";
    //player->setMedia(QMediaContent(QUrl(url)));

}

PlayVideo::~PlayVideo()
{
    delete ui;
}

void PlayVideo::on_testVideo_clicked(bool flag)
{
    if(flag==true){
        // 处理播放
        // 实例化窗口
#if 0
        videoWidget=new QVideoWidget(this);
        videoWidget->resize(600,500);
        // 实例化播放器
        player=new QMediaPlayer(this);
        // 设置到窗口播放
        player->setVideoOutput(videoWidget);
        // 设置播放的内容
        player->setMedia(QMediaContent(QUrl::fromLocalFile("E:/百度网盘下载/在线教育项目/1-阿里云上传测试视频/test_video.mp4")));
        // 设置URL
        //QString url="https://www.bilibili.com/video/BV1Ky4y1F7Rc/?spm_id_from=333.1007.tianma.2-1-4.click&vd_source=7244cdd8c7d347776bc576f7afef7c8b";
        //player->setMedia(QMediaContent(QUrl(url)));
#endif
        // 开始播放
        player->play();

        // 将按钮标签更改为清空
        ui->testVideo->setText("暂停");
    }

    else
    {
        // 处理暂停
        player->stop();
        // 将按钮标签更改为播放
        ui->testVideo->setText("播放");
    }
}
