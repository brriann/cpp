// Brian Foster (20456181) - CS2B - HW6
// W21 CS F002B 02W Cecil 31357
// Predator Simulation
//
// Client to create and seed a World
// Steps to simulate predator-prey interaction
// Movement, hunting, breeding, starving

#include <iostream>
#include <ctime>

#include "Ant.h"
#include "Doodlebug.h"
#include "World.h"
#include "Commons.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::get;
using std::make_tuple;

/* -------------------------------------------------------------
CONSTANTS AND UTILITY VARIABLES
------------------------------------------------------------- */

const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;

/* -------------------------------------------------------------
INITIALIZATION
------------------------------------------------------------- */

// track 0-indexed round for moving/starving/breeding calculations
int roundNumber = 0;

// global world to use in client
World* world = new World();

/* -------------------------------------------------------------
FUNCTION DECLARATIONS
------------------------------------------------------------- */

void simulateOneStep();
void display(World*);
void displayCensus();
void huntDoodlebugs();
bool findAdjacentMeal(Organism*, IntTuple&);
IntTuple getAdjacentCellByDirection(IntTuple, MoveDirection);
void moveOrganismsByType(char);
void breedOrganismsByType(char);
bool findAdjacentEmpty(Organism*, IntTuple&);
void starveDoodlebugs();
void endOfRound(World*);

/* -------------------------------------------------------------
MAIN CLIENT
------------------------------------------------------------- */

int main()
{
   // seed rand per time, which will give different pseudorandom results
   srand(time(0));

   // initialize world with doodlebugs and ants
   world->seed(INITIAL_ANTS, INITIAL_DOODLEBUGS);

   // run step and prompt user for Enter / next step
   bool firstIteration = true;

   do
   {
      // display initial world once before running steps
      if (firstIteration)
      {
         cout << "\nInitial World:\n";
      }
      else
      {
         simulateOneStep();
      }

      display(world);

      cout << "\n\nPress enter for next step\n";

      if (firstIteration)
      {
         firstIteration = false;
      }

   } while (cin.get() == '\n');

   return 0;
}

/* -------------------------------------------------------------
FUNCTION DEFINITIONS
------------------------------------------------------------- */

///<summary>Run a full cycle of movement, breeding, hunting, starving</summary>
void simulateOneStep()
{
   // display start of round census
   cout << "\n\pre  round " << roundNumber << " census:";
   displayCensus();

   // hunt doodlebugs
   huntDoodlebugs();

   // move doodlebugs that failed at hunting
   moveOrganismsByType(Doodlebug::CHAR_DOODLEBUG);

   // move ants
   moveOrganismsByType(Ant::CHAR_ANT);

   // breed doodlebugs
   breedOrganismsByType(Doodlebug::CHAR_DOODLEBUG);

   // breed ants
   breedOrganismsByType(Ant::CHAR_ANT);

   // starve doodlebugs
   starveDoodlebugs();

   // display end of round census
   cout << "\npost round " << roundNumber << " census:";
   displayCensus();

   // end of round maintennance
   endOfRound(world);
}

///<summary>Display the world to cout</summary>
///<param name="world">World*, world to display</param>
void display(World* world)
{
   cout << world->display();
}

///<summary>Display Organism counts by type to cout</summary>
void displayCensus()
{
   // count Ants and Doodlebugs in World, and display results
   int antCounter = 0;
   int doodlebugCounter = 0;
   for (auto row : world->grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr)
         {
            if (cell->getType() == Ant::CHAR_ANT)
            {
               antCounter++;
            }
            else if (cell->getType() == Doodlebug::CHAR_DOODLEBUG)
            {
               doodlebugCounter++;
            }
         }
      }
   }

   cout << " | antCounter: " << antCounter 
      << " | doodlebugCounter: " << doodlebugCounter;
}

///<summary>Attempt a hunt for each Doodlebug in the World</summary>
void huntDoodlebugs()
{
   for (auto row : world->grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr 
            && cell->getType() == Doodlebug::CHAR_DOODLEBUG)
         {
            // only Doodlebugs that have not moved/hunted this round can hunt
            if (!cell->ateThisRound() 
               && !cell->getHasAttemptedMove())
            {
               // find adjacent Ant to eat
               IntTuple mealLocation;
               bool huntingSuccess = findAdjacentMeal(cell, mealLocation);
               if (huntingSuccess)
               {
                  IntTuple oldLocation = cell->getLocation();

                  // delete ant from World
                  Organism* antToBeEaten = 
                     world->grid[get<0>(mealLocation)][get<1>(mealLocation)];

                  delete antToBeEaten;
                  antToBeEaten = nullptr;

                  // delete ant references from World and range-based row
                  world->grid[get<0>(mealLocation)]
                     [get<1>(mealLocation)] = nullptr;
                  row[get<1>(mealLocation)] = nullptr;

                  // update Doodlebug references, in World and row
                  world->grid[get<0>(mealLocation)]
                     [get<1>(mealLocation)] = cell;
                  row[get<1>(mealLocation)] = cell;

                  // update Doodlebug's location internally
                  cell->setLocation(make_tuple(get<0>(mealLocation), 
                     get<1>(mealLocation)));

                  // pointer maintennance in World and row
                  world->grid[get<0>(oldLocation)]
                     [get<1>(oldLocation)] = nullptr;
                  row[get<1>(oldLocation)] = nullptr;

                  // update Doodlebug activity trackers
                  cell->setLastAgeAte(cell->getAge());
                  cell->setHasAttemptedMove(true);
               }
            }
         }
      }
   }
}

///<summary>Look for Ants for adjacent Doodlebug to eat</summary>
///<param name="hunter">Organism*, Doodlebug with location</param>
///<param name="foundMealOutput">IntTuple&, parameter to output meal</param>
///<returns>bool, true if found adjacent meal<returns>
bool findAdjacentMeal(Organism* hunter, IntTuple& foundMealOutput)
{
   bool foundMeal = false;
   IntTuple huntingLocation;
   Organism* cell;

   // will search for food in a clockwise order, starting at UP
   IntTuple hunterLocation = hunter->getLocation();

   // UP
   huntingLocation = 
      getAdjacentCellByDirection(hunterLocation, MoveDirection::UP);
   if (world->isLocationValid(huntingLocation))
   {
      cell = world->grid[get<0>(huntingLocation)][get<1>(huntingLocation)];
      if (!foundMeal
         && cell != nullptr
         && cell->getType() == Ant::CHAR_ANT)
      {
         foundMeal = true;
         foundMealOutput = huntingLocation;
      }
   }

   // RIGHT
   huntingLocation = 
      getAdjacentCellByDirection(hunterLocation, MoveDirection::RIGHT);
   if (world->isLocationValid(huntingLocation))
   {
      cell = world->grid[get<0>(huntingLocation)][get<1>(huntingLocation)];
      if (!foundMeal
         && cell != nullptr
         && cell->getType() == Ant::CHAR_ANT)
      {
         foundMeal = true;
         foundMealOutput = huntingLocation;
      }
   }

   // DOWN
   huntingLocation = 
      getAdjacentCellByDirection(hunterLocation, MoveDirection::DOWN);
   if (world->isLocationValid(huntingLocation))
   {
      cell = world->grid[get<0>(huntingLocation)][get<1>(huntingLocation)];
      if (!foundMeal
         && cell != nullptr
         && cell->getType() == Ant::CHAR_ANT)
      {
         foundMeal = true;
         foundMealOutput = huntingLocation;
      }
   }

   // LEFT
   huntingLocation = 
      getAdjacentCellByDirection(hunterLocation, MoveDirection::LEFT);
   if (world->isLocationValid(huntingLocation))
   {
      cell = world->grid[get<0>(huntingLocation)][get<1>(huntingLocation)];
      if (!foundMeal
         && cell != nullptr
         && cell->getType() == Ant::CHAR_ANT)
      {
         foundMeal = true;
         foundMealOutput = huntingLocation;
      }
   }

   return foundMeal;
}

///<summary>Helper to get coordinates of an adjacent cell</summary>
///<param name="currentLocation">IntTuple, location to search from</param>
///<param name="direction">direction to determine adjacent cell</param>
///<returns>IntTuple, adjacent cell coordinates<returns>
IntTuple getAdjacentCellByDirection(IntTuple currentLocation, 
   MoveDirection direction)
{
   switch (direction)
   {
      case MoveDirection::UP:
         return make_tuple(get<0>(currentLocation) - 1, 
            get<1>(currentLocation));
      case MoveDirection::DOWN:
         return make_tuple(get<0>(currentLocation) + 1, 
            get<1>(currentLocation));
      case MoveDirection::RIGHT:
         return make_tuple(get<0>(currentLocation), 
            get<1>(currentLocation) + 1);
      case MoveDirection::LEFT:
         return make_tuple(get<0>(currentLocation), 
            get<1>(currentLocation) - 1);
   }
}

///<summary>For each organism of type, attempt movement</summary>
///<param name="organismType">char, representation of Organism</param>
void moveOrganismsByType(char organismType)
{
   int rowCounter = 0;
   for (auto row : world->grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr && cell->getType() == organismType)
         {
            // generate a potential location to move to
            cell->generateProposedLocation();

            // only move if Organism hasn't moved yet, and location is valid
            if (!cell->ateThisRound() 
               && !cell->getHasAttemptedMove() 
               && world->isLocationValidAndEmpty(cell->getProposedLocation()))
            {
               IntTuple oldLocation = cell->getLocation();

               // update the Organism's location, internally
               cell->move();

               // update pointers in World as Organism moves
               world->grid[get<0>(cell->getProposedLocation())]
                  [get<1>(cell->getProposedLocation())] = cell;
               world->grid[get<0>(oldLocation)][get<1>(oldLocation)] = nullptr;

               // update range-based loop with correct pointer if necessary
               if (get<0>(cell->getProposedLocation()) == rowCounter)
               {
                  row[get<1>(cell->getProposedLocation())] = cell;
                  row[get<1>(oldLocation)] = nullptr;
               }
            }
            else
            {
               cell->setHasAttemptedMove(true);
            }
         }
      }
      rowCounter++;
   }
}

///<summary>For each organism of type, attempt breeding</summary>
///<param name="organismType">char, representation of Organism</param>
void breedOrganismsByType(char organismType)
{
   for (auto row : world-> grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr && cell->getType() == organismType)
         {
            // Attempt breed- success determined internally
            Organism* babyOrganism = cell->breed();
            if (babyOrganism != nullptr)
            {
               IntTuple emptyLocation;
               if (findAdjacentEmpty(cell, emptyLocation))
               {
                  // set the baby's location, internally
                  babyOrganism->setLocation(emptyLocation);

                  // update pointer for baby in World
                  world->grid[get<0>(emptyLocation)]
                     [get<1>(emptyLocation)] = babyOrganism;

               }
            }
         }
      }
   }
}

///<summary>For breeding organism, find adjacent empty cell to breed</summary>
///<param name="breeder">Organism*, breeding Organism with location</param>
///<param name="foundEmptyOutput">IntTuple&, output of empty cell if found</param>
///<returns>bool, true if found adjacent empty cell to breed<returns>
bool findAdjacentEmpty(Organism* breeder, IntTuple& foundEmptyOutput)
{
   bool foundEmpty = false;
   IntTuple breedingLocation;
   Organism* cell;

   // will search for breeding spot in a clockwise order from UP
   IntTuple breederLocation = breeder->getLocation();

   // UP
   breedingLocation = 
      getAdjacentCellByDirection(breederLocation, MoveDirection::UP);
   if (world->isLocationValid(breedingLocation))
   {
      cell = world->grid[get<0>(breedingLocation)][get<1>(breedingLocation)];
      if (!foundEmpty
         && cell == nullptr)
      {
         foundEmpty = true;
         foundEmptyOutput = breedingLocation;
      }
   }

   // RIGHT
   breedingLocation = 
      getAdjacentCellByDirection(breederLocation, MoveDirection::RIGHT);
   if (world->isLocationValid(breedingLocation))
   {
      cell = world->grid[get<0>(breedingLocation)][get<1>(breedingLocation)];
      if (!foundEmpty
         && cell == nullptr)
      {
         foundEmpty = true;
         foundEmptyOutput = breedingLocation;
      }
   }

   // DOWN
   breedingLocation = 
      getAdjacentCellByDirection(breederLocation, MoveDirection::DOWN);
   if (world->isLocationValid(breedingLocation))
   {
      cell = world->grid[get<0>(breedingLocation)][get<1>(breedingLocation)];
      if (!foundEmpty
         && cell == nullptr)
      {
         foundEmpty = true;
         foundEmptyOutput = breedingLocation;
      }
   }

   // LEFT
   breedingLocation = 
      getAdjacentCellByDirection(breederLocation, MoveDirection::LEFT);
   if (world->isLocationValid(breedingLocation))
   {
      cell = world->grid[get<0>(breedingLocation)][get<1>(breedingLocation)];
      if (!foundEmpty
         && cell == nullptr)
      {
         foundEmpty = true;
         foundEmptyOutput = breedingLocation;
      }
   }

   return foundEmpty;
}

///<summary>For each Doodlebug on the board, delete if starved</summary>
void starveDoodlebugs()
{
   for (auto row : world->grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr && cell->getType() == Doodlebug::CHAR_DOODLEBUG)
         {
            // determine if Organism should starve, internally
            bool shouldStarve = cell->starve();
            if (shouldStarve)
            {
               IntTuple starveLocation = cell->getLocation();

               delete cell;
               world->grid[get<0>(starveLocation)]
                  [get<1>(starveLocation)] = nullptr;
               row[get<1>(starveLocation)] = nullptr;
            }
         }
      }
   }
}

///<summary>Perform maintenance tasks at end of round</summary>
///<param name="world">World*, world to maintain</param>
void endOfRound(World* world)
{
   for (auto row : world->grid)
   {
      for (auto cell : row)
      {
         if (cell != nullptr)
         {
            cell->setHasAttemptedMove(false);
            cell->incrementAge();
         }
      }
   }
   roundNumber++;
}