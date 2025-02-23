#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QVBoxLayout>

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = nullptr);
    ~VideoPlayer();

private slots:
    void openFile();
    void play();

private:
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videoWidget;
    QPushButton *openButton;
    QPushButton *playButton;
    QVBoxLayout *layout;
};

#endif // VIDEOPLAYER_H
