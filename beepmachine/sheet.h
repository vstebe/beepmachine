#ifndef SHEET_H
#define SHEET_H

#include <QVector>
#include "playablenote.h"

class Sheet
{
public:
    Sheet(const QVector<PlayableNote>& notes, int tempo);
    int getTempo();
    QVector<PlayableNote> getNotes();

private:
    QVector<PlayableNote> _notes;
    int _tempo;
};

#endif // SHEET_H
