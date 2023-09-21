#include "widget01.h"
#include"register.h"
#include <QApplication>
#include "player.h"
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QSettings>
#include <QIcon>
#include <QUrl>
#include"musicplayer.h"
static bool associateFileTypes()
{
    QString displayName = QGuiApplication::applicationDisplayName();
    QString filePath = QCoreApplication::applicationFilePath();
    QString fileName = QFileInfo(filePath).fileName();

    const QString key = QStringLiteral("HKEY_CURRENT_USER\\Software\\Classes\\Applications\\") + fileName;
    QSettings settings(key, QSettings::NativeFormat);
    if (settings.status() != QSettings::NoError) {
        qWarning() << "Cannot access registry key" << key;
        return false;
    }
    settings.setValue(QStringLiteral("FriendlyAppName"), displayName);

    settings.beginGroup(QStringLiteral("SupportedTypes"));
    QMimeDatabase mimeDatabase;
    const QStringList supportedMimeTypes = MusicPlayer::supportedMimeTypes();
    for (const QString &fileType : supportedMimeTypes) {
        const QStringList suffixes = mimeDatabase.mimeTypeForName(fileType).suffixes();
        for (QString suffix : suffixes) {
            suffix.prepend('.');
            settings.setValue(suffix, QString());
        }
    }
    settings.endGroup();

    settings.beginGroup(QStringLiteral("shell"));
    settings.beginGroup(QStringLiteral("open"));
    settings.setValue(QStringLiteral("FriendlyAppName"), displayName);
    settings.beginGroup(QStringLiteral("Command"));
    settings.setValue(QStringLiteral("."),
                      QLatin1Char('"') + QDir::toNativeSeparators(filePath) + QStringLiteral("\" \"%1\""));

    return true;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Player Example");
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser parser;
    QCommandLineOption customAudioRoleOption("custom-audio-role",
                                             "Set a custom audio role for the player.",
                                             "role");
    parser.setApplicationDescription("Qt MultiMedia Player Example");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addOption(customAudioRoleOption);
    parser.addPositionalArgument("url", "The URL(s) to open.");
    parser.process(a);

    Player player;
    if (parser.isSet(customAudioRoleOption))
        player.setCustomAudioRole(parser.value(customAudioRoleOption));

    if (!parser.positionalArguments().isEmpty() && player.isPlayerAvailable()) {
        QList<QUrl> urls;
        for (auto &a: parser.positionalArguments())
            urls.append(QUrl::fromUserInput(a, QDir::currentPath(), QUrl::AssumeLocalFile));
        player.addToPlaylist(urls);
    }

    MusicPlayer mPlayer;

    if (!parser.positionalArguments().isEmpty())
        mPlayer.playUrl(QUrl::fromUserInput(parser.positionalArguments().constFirst(), QDir::currentPath(), QUrl::AssumeLocalFile));

    const QRect availableGeometry = QApplication::desktop()->availableGeometry(&mPlayer);
    mPlayer.resize(availableGeometry.width() / 6, availableGeometry.height() / 17);

    //player.show();

    Widget01 w;
    w.show();
    return a.exec();
}
