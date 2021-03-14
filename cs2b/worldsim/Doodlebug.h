#pragma once

#ifndef Doodlebug_h
#define Doodlebug_h

#include "Organism.h";
#include "Commons.cpp";

class Doodlebug : public Organism
{
public:
   Doodlebug();
   Doodlebug(IntTuple);
   void move() override;
   Doodlebug* breed() override;
   int getType() override;
   bool starve() override;
   bool ateThisRound() override;
   static const char CHAR_DOODLEBUG;
};

#endif // Doodlebug_h