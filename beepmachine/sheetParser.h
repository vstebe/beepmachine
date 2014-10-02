#ifndef SHEETPARSER_H
#define SHEETPARSER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "sheet.h"

class SheetParser
{
private:
    QString _fileName;
    Sheet * _sh;
    QFile * _file;
    Note getNote(QString ligne);
    int numLigne;

public:
    SheetParser();
    SheetParser(QString fileName);
    Sheet getSheet();


};


#endif // SHEETPARSER_H
