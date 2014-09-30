#include "sheet.h"

Sheet::Sheet(const QVector<Note> &notes, int tempo)
{
    _notes = notes;
    _tempo = tempo;
}
