#include "sheetParser.h"

SheetParser::SheetParser()
{
}
SheetParser::SheetParser(QString fileName)
{
    _fileName = fileName;
}

Sheet SheetParser::getSheet()
{
    int tempo;
    QVector <Note> vec;

   _file = new QFile(_fileName);
   _file->open(QIODevice::ReadOnly | QIODevice::Text);
   QTextStream flux(_file);

   QString ligne;
   ligne = flux.readLine();

   bool ok;
   tempo = ligne.toInt(&ok, 10);    //first line


   while(! flux.atEnd())            //other lines
   {
       ligne = flux.readLine();
       Note n = getNote(ligne);
       vec.push_back(n);
   }
   return Sheet(vec, tempo);
}


Note SheetParser::getNote(QString ligne)
{
    bool ok;
    if (ligne[0] == '/') //special command
    {
        if (ligne == "/r")
             return Note(WHOLE, SILENCE);
        if (ligne == "/r.")
             return Note(WHOLE, SILENCE);
        if (ligne == "/r.")
             return Note(WHOLE_POINT, SILENCE);
        if(ligne == "/b")
             return Note(HALF, SILENCE);
        if (ligne == "/b.")
             return Note(HALF_POINT, SILENCE);
        if (ligne == "/n")
             return Note(QUARTER, SILENCE);
        if (ligne == "/n.")
             return Note(QUARTER_POINT, SILENCE);
        if (ligne ==  "/c")
             return Note(EIGHTH, SILENCE);
        if (ligne == "/dc")
             return Note(SIXTEENTH, SILENCE);
    }
    else if (ligne[0] == '#')   //comment
    {
        //do nothing
    }
    else
    {
       QStringList liste = ligne.split(":");
       TYPE_NOTE type;
       LENGTH length;
       int octave = liste[2].toInt(&ok, 10);

       if (liste[0] ==  "do" || liste[0] == "C")
            type=DO;
       else if (liste[0] == "do#" || liste[0] == "C#")
            type=DO_D;
       else if (liste[0] ==  "re" || liste[0] == "D")
            type=RE;
       else if (liste[0] ==  "re#" || liste[0] == "D#")
            type=RE_D;
       else if (liste[0] ==   "mi" || liste[0] == "E")
            type=MI;
       else if (liste[0] ==   "fa" || liste[0] == "F")
            type=FA;
       else if (liste[0] ==   "fa#" || liste[0] == "F#")
            type=FA_D;
       else if (liste[0] ==   "sol" || liste[0] == "G")
            type=SOL;
       else if (liste[0] ==   "sol#" || liste[0] == "G#")
            type=SOL_D;
       else if (liste[0] ==   "la" || liste[0] == "A")
            type=LA;
       else if (liste[0] ==  "la#" || liste[0] == "A#")
            type=LA_D;
       else if (liste[0] ==   "si" || liste[0] == "B")
            type=SI;


       if (liste[1] == "r")
            length=WHOLE;
       else if (liste[1] == "r.")
            length=WHOLE_POINT;
       else if (liste[1] == "b")
            length=HALF;
       else if (liste[1] == "b.")
            length=HALF_POINT;
       else if (liste[1] == "n")
            length=QUARTER;
       else if (liste[1] == "n.")
            length=QUARTER_POINT;
       else if (liste[1] == "c")
            length=EIGHTH;
       else if (liste[1] == "dc")
            length=SIXTEENTH;

       return Note(length, type, octave);
    }
    return Note();
}
