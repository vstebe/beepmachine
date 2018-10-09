#include "note.h"

Note::Note(LENGTH length, TYPE_NOTE typeNote, int octave) : _length(length), _typeNote(typeNote), _octave(octave) {}

Note::Note(LENGTH length, TYPE_NOTE typeNote) : _length(length), _typeNote(typeNote){}


Note::Note() :  _length(QUARTER), _typeNote(LA), _octave(3) {}

LENGTH Note::getLength() const
{
    return _length;
}

TYPE_NOTE Note::getTypeNote() const
{
    return _typeNote;
}

int Note::getOctave() const
{
    return _octave;
}
