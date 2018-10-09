#ifndef MIDIPARSER_H
#define MIDIPARSER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "sheet.h"
#include "parser.h"
class MidiParser : public Parser
{
private:
    QString _fileName;
    Sheet * _sh;
public:
    MidiParser();
    MidiParser(QString fileName);
    Sheet getSheet();


};


#endif // SHEETPARSER_H
