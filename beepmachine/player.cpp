#include "player.h"

#include <QDebug>
#include <math.h>

Player::Player(Sheet *sheet)
{
    _sheet = sheet;
}

void Player::run()
{
    QVector<PlayableNote> notes = _sheet->getNotes();
    for(int i=0; i<notes.size(); i++) {
        if (notes[i].getPitch() < 0) {
            playSilence(notes[i].getDuration() * 0.55);
        } else {
            playNote(notes[i].getPitch(), notes[i].getDuration() * 0.55);
        }
    }
}
