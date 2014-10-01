#include <QCoreApplication>

#include <QVector>
#include "sheet.h"
#include "beepplayer.h"
#include "sheetParser.h"
#include "config.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString filename = a.arguments()[1];

    SheetParser parser(filename);
    Sheet sheet = parser.getSheet();


    BeepPlayer debugPlayer(&sheet);
    debugPlayer.run();


    return 0;
}
