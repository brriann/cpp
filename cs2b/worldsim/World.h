#pragma once

#ifndef World_h
#define World_h

#include <vector>
#include <string>

#include "Organism.h"
#include "Commons.cpp"

using std::vector;
using std::string;

class World
{
public:
   World();
   void seed(int, int);
   string display();
   bool isLocationValid(IntTuple);
   bool isLocationValidAndEmpty(IntTuple);
   static const char EMPTY_CELL;
   static const int GRID_DIMENSION;
   vector< vector<Organism*> > grid;
};

#endif // World_h