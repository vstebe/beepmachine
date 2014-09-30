#ifndef NOTE_H
#define NOTE_H

#include "config.h"

class Note
{
public:
    Note(LENGTH length, TYPE_NOTE typeNote, int octave);

private:
    LENGTH _length;
    TYPE_NOTE _typeNote;
    int _octave;
};

#endif // NOTE_H
