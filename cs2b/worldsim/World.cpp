
#include <string>
#include <sstream>
#include <iomanip>

#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"

using std::string;
using std::endl;
using std::setw;

using std::tuple;
using std::make_tuple;
using std::get;

/* -------------------------------------------------------------
CONSTANTS AND UTILITY VARIABLES
------------------------------------------------------------- */

const int DISPLAY_CELL_WIDTH = 3;

/* -------------------------------------------------------------
INITIALIZATION
------------------------------------------------------------- */

const char World::EMPTY_CELL = '.';

// 20x20 grid dimension/boundaries - these 3 const's are related.
const int World::GRID_DIMENSION = 20;
const int MIN_LOCATION_DIMENSION = 0;
const int MAX_LOCATION_DIMENSION = 19;

/* -------------------------------------------------------------
WORLD CLASS - MEMBER FUNCTION DEFINITIONS
------------------------------------------------------------- */

// Default constructor
World::World()
{
   // initialize empty grid
   for (int i = 0; i < GRID_DIMENSION; i++)
   {  
      vector<Organism*> row;
      for (int j = 0; j < GRID_DIMENSION; j++)
      {
         row.push_back(nullptr);
      }
      grid.push_back(row);
   }
}

///<summary>Seed the world with Ants and Doodlebugs</summary>
///<param name="antCount">int, number of Ants to seed</param>
///<param name="doodlebugCount">int, number of Doodlebugs to seed</param>
void World::seed(int antCount, int doodlebugCount)
{
   // seed doodlebugs
   for (int i = 0; i < doodlebugCount; i++)
   {
      IntTuple proposedLocation;
      do
      {
         // generate a valid, empty location
         proposedLocation = 
            make_tuple(rand() % GRID_DIMENSION, rand() % GRID_DIMENSION);
      } while (!isLocationValidAndEmpty(proposedLocation));

      // create Doodlebug with location, and assign to grid
      Doodlebug* doodlebug = new Doodlebug(proposedLocation);
      grid[get<0>(proposedLocation)]
         [get<1>(proposedLocation)] = doodlebug;
   }

   // seed ants
   for (int i = 0; i < antCount; i ++)
   {
      IntTuple proposedLocation;
      do
      {
         // generate a valid, empty location
         proposedLocation =
            make_tuple(rand() % GRID_DIMENSION, rand() % GRID_DIMENSION);
      } while (!isLocationValidAndEmpty(proposedLocation));

      // create Ant with location, and assign to grid
      Ant* ant = new Ant(proposedLocation);
      grid[get<0>(proposedLocation)][get<1>(proposedLocation)] = ant;
   }
}

///<summary>Generate string representation of the World as a grid</summary>
///<returns>string, representation of World<returns>
string World::display()
{
   std::stringstream ss;

   // origin
   ss << endl << setw(DISPLAY_CELL_WIDTH) << " ";

   // column axis labels
   for (int i = 0; i < GRID_DIMENSION; i++)
   {
      ss << setw(DISPLAY_CELL_WIDTH) << i;
   }
   ss << endl;

   int counter = 0;
   for (auto& row:grid)
   {
      // row axis label
      ss << setw(DISPLAY_CELL_WIDTH) << counter++;

      for (auto& cell:row)
      {
         // print . for empty, o for Ant, X for Doodlebug
         char displayChar = cell == nullptr 
            ? World::EMPTY_CELL 
            : cell->getType();

         ss << setw(DISPLAY_CELL_WIDTH) << displayChar;
      }
      ss << endl;
   }

   return ss.str();
}

///<summary>Check if location exists within bounds of grid</summary>
///<param name="locationToCheck">IntTuple, location to check</param>
///<returns>bool, true if location is valid<returns>
bool World::isLocationValid(IntTuple locationToCheck)
{
   return get<0>(locationToCheck) >= MIN_LOCATION_DIMENSION
      && get<0>(locationToCheck) <= MAX_LOCATION_DIMENSION
      && get<1>(locationToCheck) >= MIN_LOCATION_DIMENSION
      && get<1>(locationToCheck) <= MAX_LOCATION_DIMENSION;
}

///<summary>Check if location is valid and empty</summary>
///<param name="locationToCheck">IntTuple, location to check</param>
///<returns>bool, true if location is valid and empty<returns>
bool World::isLocationValidAndEmpty(IntTuple locationToCheck)
{
   return (isLocationValid(locationToCheck)
      && grid[get<0>(locationToCheck)][get<1>(locationToCheck)] == nullptr);
}
