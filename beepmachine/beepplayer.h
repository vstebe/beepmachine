#ifndef BEEPPLAYER_H
#define BEEPPLAYER_H
#include "player.h"
class BeepPlayer : public Player
{
public:
    BeepPlayer(Sheet * sheet);
    void playNote(float freq, float duration);
};

#endif // BEEPPLAYER_H
