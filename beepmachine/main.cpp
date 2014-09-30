#include <QCoreApplication>

#include <QVector>
#include "sheet.h"
#include "note.h"
#include "beepplayer.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<Note> notes;
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));
    notes.append(Note(QUARTER, RE_D, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));

    notes.append(Note(QUARTER, RE_D, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));

    notes.append(Note(QUARTER, RE_D, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));

    notes.append(Note(QUARTER, RE_D, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));

    notes.append(Note(QUARTER, MI, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));


    notes.append(Note(QUARTER, MI, 3));
    notes.append(Note(QUARTER, FA, 3));
    notes.append(Note(HALF, SOL, 3));
    notes.append(Note(HALF, DO, 3));


    Sheet sheet(notes, 150);

    BeepPlayer player(&sheet);
    player.run();

    return a.exec();
}
