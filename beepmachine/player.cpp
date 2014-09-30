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

        qDebug() << "diffOctaves " << diffOctave << " diffHalfTones : " << diffHalfTones;

        diffHalfTones += diffOctave * 12;

        float freq = LA_REF * pow(2, ((float)diffHalfTones) / 12.f);

        qDebug() << diffHalfTones << " " << freq;
    }
}
