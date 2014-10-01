#ifndef EXPORTBEEPPLAYER_H
#define EXPORTBEEPPLAYER_H

#include"player.h"

class ExportBeepPlayer : public Player
{
public:
    ExportBeepPlayer(Sheet * sheet);
    void run();

protected:
    void playNote(float freq, float duration);
    void playSilence(float duration);
};

#endif // EXPORTBEEPPLAYER_H
