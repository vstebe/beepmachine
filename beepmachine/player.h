#ifndef PLAYER_H
#define PLAYER_H

#include"sheet.h"

class Player
{
public:
    Player(Sheet * sheet);
    virtual void run();

protected:
    virtual void playNote(float freq, float duration) = 0;
    virtual void playSilence(float duration) = 0;

    Sheet * _sheet;
};

#endif // PLAYER_H
