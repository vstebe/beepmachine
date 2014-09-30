#include "sheet.h"

Sheet::Sheet(const QVector<Note> &notes, int tempo)
{
    _notes = notes;
    _tempo = tempo;
}

QVector<Note> Sheet::getNotes()
{
    return _notes;
}

int Sheet::getTempo()
{
    return _tempo;
}
