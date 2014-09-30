#include "player.h"

#include <QDebug>
#include <math.h>

Player::Player(Sheet *sheet)
{
    _sheet = sheet;
}

void Player::run()
{
    QVector<Note> notes = _sheet->getNotes();


    QVectorIterator<Note> it(notes);
    while (it.hasNext())
    {
        Note note = it.next();
        int diffOctave =  note.getOctave() - OCTAVE_REF;
        int diffHalfTones = note.getTypeNote() - LA;
        diffHalfTones += diffOctave * 12;

        float freq = LA_REF * pow(2, ((float)diffHalfTones) / 12.f);

        float duration;

        switch(note.getLength())
        {
            case WHOLE:
                duration = _sheet->getTempo() * 4;
                break;
            case HALF:
                duration = _sheet->getTempo() * 2;
                break;
            case QUARTER:
                duration = _sheet->getTempo();
                break;
            case EIGHTH:
                duration = _sheet->getTempo() / 2.f;
                break;
            case SIXTEENTH:
                duration = _sheet->getTempo() / 4.f;
                break;
            case WHOLE_POINT:
                duration = _sheet->getTempo() * 6;
                break;
            case HALF_POINT:
                duration = _sheet->getTempo() * 3;
                break;
            case QUARTER_POINT:
                duration = _sheet->getTempo() * 1.5f;
                break;
        }

        playNote(freq, duration);
    }
}
