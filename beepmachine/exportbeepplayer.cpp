#include "exportbeepplayer.h"
#include <iostream>

#include <QString>

ExportBeepPlayer::ExportBeepPlayer(Sheet * sheet) : Player(sheet)
{
}

void ExportBeepPlayer::run()
{
    std::cout << "#!/bin/sh" << std::endl;
    std::cout << "echo Created with BeepMachine" << std::endl;
    Player::run();
}

void ExportBeepPlayer::playNote(float freq, float duration)
{
    QString cmd= QString("beep -f ") + QString::number(freq) + " " + " -l " + QString::number(duration - 3);
    std::cout << cmd.toStdString() << std::endl;
    playSilence(3);
}

void ExportBeepPlayer::playSilence(float duration)
{
    QString cmd("sleep ");
    cmd += QString::number(duration / 1000);
    std::cout << cmd.toStdString() << std::endl;
}
