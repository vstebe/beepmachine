#ifndef NOTE_H
#define NOTE_H

#include "config.h"

class Note
{
public:
    Note(LENGTH length, TYPE_NOTE typeNote, int octave);
    Note(LENGTH length, TYPE_NOTE typeNote);
    Note();
    LENGTH getLength() const;
    TYPE_NOTE getTypeNote() const;
    int getOctave() const;

private:
    LENGTH _length;
    TYPE_NOTE _typeNote;
    int _octave;
};

#endif // NOTE_H
