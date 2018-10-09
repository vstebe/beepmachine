#include <QCoreApplication>

#include <QVector>
#include "sheet.h"
#include "beepplayer.h"
#include "sheetParser.h"
#include "midiParser.h"
#include "config.h"
#include "exportbeepplayer.h"
#include "debugplayer.h"
#include <QDebug>

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(a.arguments().size() == 1)
    {
        std::cerr << "Ligne de commande non valide" << std::endl;
        return 1;
    }

    bool debug = false;
    bool bashexport = false;

    QString filename;



    for(int i=0; i<a.arguments().size(); i++)
    {

        if(a.arguments()[i] == "-d")
            debug = true;
        else if(a.arguments()[i] == "-e")
            bashexport = true;
        else
            filename = a.arguments()[i];
    }

    if(debug && bashexport)
    {
        std::cerr << "Peut pas etre à la fois debug et export" << std::endl;
        return 1;
    }

    Player * player;

    Parser * parser;
    if (filename.endsWith(".midi") || filename.endsWith(".mid")) {
        parser = new MidiParser(filename);
    } else {
        parser = new SheetParser(filename);
    }


    Sheet sheet = parser->getSheet();

    if(debug)
        player = new DebugPlayer(&sheet);
    else if(bashexport)
        player = new ExportBeepPlayer(&sheet);
    else
        player = new BeepPlayer(&sheet);

    player->run();

    //delete player;

    delete parser;
    return 0;
}
