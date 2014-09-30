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
   _file = new QFile(_fileName);
   _file->open(QIODevice::ReadOnly | QIODevice::Text);
   QTextStream flux(_file);

   QString ligne;
   while(! flux.atEnd())
   {
       ligne = flux.readLine();
       //traitement de la ligne
   }

}


Note SheetParser::_getNote(QString ligne)
{

}
