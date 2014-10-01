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
   tempo = ligne.toInt(ok&, 10);    //first line


   while(! flux.atEnd())            //other lines
   {
       ligne = flux.readLine();
       Note n = getNote(ligne);
       vec.push_back(n);
   }
   return sheet (vec, tempo);
}


Note SheetParser::getNote(QString ligne)
{
    if (ligne[0] == "/") //special command
    {
        switch(ligne)           //SILENCE
        case "/r":
             return Note(LENGTH.WHOLE, TYPE_NOTE.SILENCE);
            break;

        case "/r.":
             return Note(LENGTH.WHOLE_POINT, TYPE_NOTE.SILENCE);
            break;

        case "/b":
             return Note(LENGTH.HALF, TYPE_NOTE.SILENCE);
            break;

        case "/b.":
             return Note(LENGTH.HALF_POINT, TYPE_NOTE.SILENCE);
            break;

        case "/n":
             return Note(LENGTH.QUARTER, TYPE_NOTE.SILENCE);
            break;

        case "/n.":
             return Note(LENGTH.QUARTER_POINT, TYPE_NOTE.SILENCE);
            break;

        case "/c":
             return Note(LENGTH.EIGHTH, TYPE_NOTE.SILENCE);
            break;

        case "/dc":
             return Note(LENGTH.SIXTEENTH, TYPE_NOTE.SILENCE);
            break;

    }
    else if (ligne[0] == "#")   //comment
    {
        //do nothing
    }
    else
    {
       QStringList liste = ligne.split(":");
       TYPE_NOTE type;
       LENGTH length;
       int octave = liste[2];

        switch (liste[0]){      //note

            case "do" || "C":
                type=TYPE_NOTE.DO;
                break;

        switch (liste[0]);
            case "do#" || "C#":
                type=TYPE_NOTE.DO_D;
                break;

        switch (liste[0]);
            case "re" || "D":
                type=TYPE_NOTE.RE;
                break;

        switch (liste[0]);
            case "re#" || "D#":
                type=TYPE_NOTE.RE_D;
                break;

        switch (liste[0]);
            case "mi" || "E":
                type=TYPE_NOTE.MI;
                break;

        switch (liste[0]);
            case "fa" || "F":
                type=TYPE_NOTE.FA;
                break;

        switch (liste[0]);
            case "fa#" || "F#":
                type=TYPE_NOTE.FA_D;
                break;

        switch (liste[0]);
            case "sol" || "G":
                type=TYPE_NOTE.SOL;
                break;

        switch (liste[0]);
            case "sol#" || "G#":
                type=TYPE_NOTE.SOL_D;
                break;

        switch (liste[0]);
            case "la" || "A":
                type=TYPE_NOTE.LA;
                break;

        switch (liste[0]);
            case "la#" || "A#":
                type=TYPE_NOTE.LA_D;
                break;

        switch (liste[0]);
            case "si" || "B":
                type=TYPE_NOTE.SI;
                break;
    }

        switch (liste[1]){      //length

        case "r":
            length=LENGTH.WHOLE;
            break;

        case "r.":
            length=LENGTH.WHOLE_POINT;
            break;

        case "b":
            length=LENGTH.HALF;
            break;

        case "b.":
            length=LENGTH.HALF_POINT;
            break;

        case "n":
            length=LENGTH.QUARTER;
            break;

        case "n.":
            length=LENGTH.QUARTER_POINT;
            break;

        case "c":
            length=LENGTH.EIGHTH;
            break;

        case "dc":
            length=LENGTH.SIXTEENTH;
            break;
        }

       return Note(length, type, octave);
    }

}
