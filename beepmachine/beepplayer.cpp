#include "beepplayer.h"

#include<QString>
#include<QDebug>
BeepPlayer::BeepPlayer(Sheet * sheet) : Player(sheet)
{

}


void BeepPlayer::playNote(float freq, float duration)
{
    QString cmd= QString("beep -f ") + QString::number(freq) + " " + " -l " + QString::number(duration - 3);
    qDebug() << cmd;
    system(cmd.toStdString().c_str());
    playSilence(3);
}

void BeepPlayer::playSilence(float duration)
{
    QString cmd("sleep ");
    cmd += QString::number(duration / 1000);
    qDebug() << cmd;
    system(cmd.toStdString().c_str());
}
