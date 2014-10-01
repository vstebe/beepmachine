#include "debugplayer.h"

#include<QString>
#include<QDebug>


DebugPlayer::DebugPlayer(Sheet * sheet) : Player(sheet)
{

}


void DebugPlayer::playNote(float freq, float duration)
{
    QString cmd= QString("beep -f ") + QString::number(freq) + " " + " -l " + QString::number(duration);
    qDebug() << cmd;
}

void DebugPlayer::playSilence(float duration)
{
    QString cmd("sleep ");
    cmd += QString::number(duration / 1000);
    qDebug() << cmd;
}
