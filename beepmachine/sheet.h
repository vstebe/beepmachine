#ifndef SHEET_H
#define SHEET_H

#include <QVector>
#include "note.h"

class Sheet
{
public:
    Sheet(const QVector<Note>& notes, int tempo);

private:
    QVector<Note> _notes;
    int _tempo;
};

#endif // SHEET_H
