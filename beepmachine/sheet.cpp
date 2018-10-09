#include "sheet.h"

Sheet::Sheet(const QVector<PlayableNote> &notes, int tempo)
{
    _notes = notes;
    _tempo = tempo;
}

QVector<PlayableNote> Sheet::getNotes()
{
    return _notes;
}

int Sheet::getTempo()
{
    return _tempo;
}
