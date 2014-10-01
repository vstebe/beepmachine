#ifndef DEBUGPLAYER_H
#define DEBUGPLAYER_H

#include "player.h"

class DebugPlayer : public Player
{
public:
    DebugPlayer(Sheet * sheet);
protected:
    void playNote(float freq, float duration);
    void playSilence(float duration);
};

#endif // DEBUGPLAYER_H
