#pragma once

#ifndef Ant_h
#define Ant_h

#include "Organism.h";
#include "Commons.cpp";

class Ant : public Organism
{
public:
   Ant();
   Ant(IntTuple);
   Ant* breed() override;
   int getType() override;
   bool starve() override;
   bool ateThisRound() override;
   static const char CHAR_ANT;
};

#endif // Ant_h