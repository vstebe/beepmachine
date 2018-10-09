#ifndef PARSER_H
#define PARSER_H

#include "sheet.h"

class Parser
{
public:
   virtual Sheet getSheet() = 0;
};

#endif // PARSER_H
