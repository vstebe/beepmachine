#include "beepplayer.h"

#include<QString>
#include<QDebug>
BeepPlayer::BeepPlayer(Sheet * sheet) : Player(sheet)
{

}


void BeepPlayer::playNote(float freq, float duration)
{
    QString cmd= QString("beep -f ") + QString::number(freq) + " " + " -l " + QString::number(duration);
    qDebug() << cmd;
    system(cmd.toStdString().c_str());
}

void BeepPlayer::playSilence(float duration)
{
    QString cmd("sleep ");
    cmd += QString::number(duration / 1000);
    system(cmd.toStdString().c_str());
}
