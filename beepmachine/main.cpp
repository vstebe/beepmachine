#include <QCoreApplication>

#include <QVector>
#include "sheet.h"
#include "note.h"
#include "player.h"
#include "config.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<Note> notes;
    notes.append(Note(HALF, FA_D, 7));

    Sheet sheet(notes, 300);

    Player player(&sheet);
    player.run();

    return a.exec();
}
