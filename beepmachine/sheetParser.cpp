#include "sheetParser.h"
#include "iostream"
#include <math.h>

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
    QVector <PlayableNote> vec;

   _file = new QFile(_fileName);
   _file->open(QIODevice::ReadOnly | QIODevice::Text);
   QTextStream flux(_file);

   QString ligne;
   ligne = flux.readLine();

   bool ok;
   tempo = ligne.toInt(&ok, 10);    //first line
   numLigne=1;


   while(! flux.atEnd())            //other lines
   {
       ligne = flux.readLine();
       numLigne++;
       if (ligne != "" && ligne[0] != '#')      //empty line or comment
       {
           Note n = getNote(ligne);
           vec.push_back(getPlayableNote(tempo, n));
       }
   }
   return Sheet(vec, tempo);
}

PlayableNote SheetParser::getPlayableNote(int tempo, const Note& note) {
    float duration = 60000.f / tempo;

    switch(note.getLength())
    {
        case WHOLE:
            duration = duration * 4;
            break;
        case HALF:
            duration = duration * 2;
            break;
        case QUARTER:
            duration = duration;
            break;
        case EIGHTH:
            duration = duration / 2.f;
            break;
        case SIXTEENTH:
            duration = duration / 4.f;
            break;
        case THIRTYSECOND:
            duration = duration / 8.f;
            break;
        case WHOLE_POINT:
            duration = duration * 6;
            break;
        case HALF_POINT:
            duration = duration * 3;
            break;
        case QUARTER_POINT:
            duration = duration * 1.5f;
            break;
        case EIGHTH_POINT:
            duration = (duration * 1.5f) / 2.f;
            break;
        case SIXTEENTH_POINT:
            duration = (duration * 1.5f) / 4.f;
            break;
        case THIRTYSECOND_POINT:
            duration = (duration * 1.5f) / 8.f;
            break;
    }


    if(note.getTypeNote() == SILENCE)
    {
        return PlayableNote(duration);
    } else {

        int diffOctave =  note.getOctave() - OCTAVE_REF;
        int diffHalfTones = note.getTypeNote() - LA;
        float freq = LA_REF * pow(2, ((float)diffHalfTones) / 12.f);

        return PlayableNote(freq, duration);
    }

}


Note SheetParser::getNote(QString ligne)
{
    bool ok;
    if (ligne[0] == '/') //special command
    {
        if (ligne == "/r")
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
        if  (ligne == "/c.")
            return Note(EIGHTH_POINT, SILENCE);
        if (ligne == "/dc")
             return Note(SIXTEENTH, SILENCE);
        if (ligne == "/dc.")
            return Note(SIXTEENTH_POINT, SILENCE);
        if (ligne == "/tc")
            return Note(THIRTYSECOND, SILENCE);
        if (ligne == "/tc.")
            return Note (THIRTYSECOND_POINT, SILENCE);
        std::cerr << "ERROR : " << numLigne << " : " << ligne.toStdString();

    }
    else
    {
       QStringList liste = ligne.split(":");
       TYPE_NOTE type;
       LENGTH length = NO_LENGTH;
       int octave;

       if (liste.size() == 3)
       {
           octave = liste[2].toInt(&ok, 10);
              if (ok)
              {
               if (liste[0] ==  "do" || liste[0] == "C")
                    type=DO;
               else if (liste[0] == "do#" || liste[0] == "C#" || liste[0] == "reb" || liste [0] == "Db")
                    type=DO_D;
               else if (liste[0] ==  "re" || liste[0] == "D")
                    type=RE;
               else if (liste[0] ==  "re#" || liste[0] == "D#" || liste[0] == "mib" || liste [0] == "Eb")
                    type=RE_D;
               else if (liste[0] ==   "mi" || liste[0] == "E"  || liste[0] == "fab" || liste [0] == "Fb")
                    type=MI;
               else if (liste[0] ==   "fa" || liste[0] == "F")
                    type=FA;
               else if (liste[0] ==   "fa#" || liste[0] == "F#" || liste[0] == "solb" || liste [0] == "Gb")
                    type=FA_D;
               else if (liste[0] ==   "sol" || liste[0] == "G")
                    type=SOL;
               else if (liste[0] ==   "sol#" || liste[0] == "G#" || liste[0] == "lab" || liste [0] == "Ab")
                    type=SOL_D;
               else if (liste[0] ==   "la" || liste[0] == "A")
                    type=LA;
               else if (liste[0] ==  "la#" || liste[0] == "A#" || liste[0] == "sib" || liste [0] == "Bb")
                    type=LA_D;
               else if (liste[0] ==   "si" || liste[0] == "B" || liste[0] == "dob" || liste [0] == "Cb")
                    type=SI;
               else
                   std::cerr << "ERROR : " << numLigne << " : " << ligne.toStdString();


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
               else if (liste[1] == "c.")
                   length=EIGHTH_POINT;
               else if (liste[1] == "dc")
                   length=SIXTEENTH;
               else if (liste[1] == "dc.")
                   length=SIXTEENTH_POINT;
               else if (liste[1] == "tc")
                   length=THIRTYSECOND;
               else if (liste[1] == "tc.")
                   length=THIRTYSECOND_POINT;
               else
                   std::cerr << "ERROR : " << numLigne << " : " << ligne.toStdString();
              }
              else
                  std::cerr << "ERROR : " << numLigne << " : " << ligne.toStdString();

       }
       else
           std::cerr << "ERROR : " << numLigne << " : " << ligne.toStdString();

       return Note(length, type, octave);
    }
return Note();
}
