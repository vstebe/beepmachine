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

        float duration = 60000.f / _sheet->getTempo();



        switch(note.getLength())
        {
            case WHOLE:
                duration = duration * 4;
                break;
            case HALF:
                duration = duration * 2;
                break;
            case QUARTER:
                duration = duration;
                break;
            case EIGHTH:
                duration = duration / 2.f;
                break;
            case SIXTEENTH:
                duration = duration / 4.f;
                break;
            case WHOLE_POINT:
                duration = duration * 6;
                break;
            case HALF_POINT:
                duration = duration * 3;
                break;
            case QUARTER_POINT:
                duration = duration * 1.5f;
                break;
            case EIGHTH_POINT:
                duration = (duration * 1.5f) / 2.f;
                break;
            case SIXTEENTH_POINT:
                duration = (duration * 1.5f)/ 4.f;
                break;
        }




        if(note.getTypeNote() == SILENCE)
        {
            playSilence(duration);
        } else {

            int diffOctave =  note.getOctave() - OCTAVE_REF;
            int diffHalfTones = note.getTypeNote() - LA;
            diffHalfTones += diffOctave * 12;

            float freq = LA_REF * pow(2, ((float)diffHalfTones) / 12.f);

            playNote(freq, duration);
        }


    }
}
