#include "videoplayer.h"
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPushButton>
#include <QVBoxLayout>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
    , mediaPlayer(new QMediaPlayer(this))
    , videoWidget(new QVideoWidget(this))
    , openButton(new QPushButton("Open", this))
    , playButton(new QPushButton("Play", this))
    , layout(new QVBoxLayout(this))
{
    layout->addWidget(videoWidget);
    layout->addWidget(openButton);
    layout->addWidget(playButton);

    mediaPlayer->setVideoOutput(videoWidget);

    connect(openButton, &QPushButton::clicked, this, &VideoPlayer::openFile);
    connect(playButton, &QPushButton::clicked, this, &VideoPlayer::play);
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Video File");
    if (!fileName.isEmpty()) {
        mediaPlayer->setSource(QUrl::fromLocalFile(fileName));
    }
}

void VideoPlayer::play()
{
    mediaPlayer->play();
}