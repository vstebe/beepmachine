#ifndef SHEETPARSER_H
#define SHEETPARSER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "sheet.h"
#include "parser.h"
#include "playablenote.h"
#include "note.h"

class SheetParser: public Parser
{
private:
    QString _fileName;
    Sheet * _sh;
    QFile * _file;
    Note getNote(QString ligne);
    PlayableNote getPlayableNote(int tempo, const Note& note);
    int numLigne;

public:
    SheetParser();
    SheetParser(QString fileName);
    Sheet getSheet();


};


#endif // SHEETPARSER_H
