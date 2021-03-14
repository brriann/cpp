
#include "Doodlebug.h"

/* -------------------------------------------------------------
CONSTANTS AND UTILITY VARIABLES
------------------------------------------------------------- */

const int DOODLEBUG_BREED_SPAN = 8;
const int DOODLEBUG_STARVE_SPAN = 3;

/* -------------------------------------------------------------
INITIALIZATION
------------------------------------------------------------- */

const char Doodlebug::CHAR_DOODLEBUG = 'X';

/* -------------------------------------------------------------
DOODLEBUG CLASS - MEMBER FUNCTION DEFINITIONS
------------------------------------------------------------- */

//Default Constructor
Doodlebug::Doodlebug() : Organism()
{
   // deliberately empty
}

///<summary>Doodlebug constructor with location</summary>
///<param name="locationCtr">IntTuple, grid location to spawn Doodlebug</param>
///<returns>Doodlebug object<returns>
Doodlebug::Doodlebug(IntTuple locationCtr) : Organism(locationCtr)
{
   // deliberately empty
}

///<summary></summary>
///<returns><returns>
void Doodlebug::move()
{
   // first, try to move as a Doodlebug - find adjacent ant and eat it
   // hunting happens in client, so ensure doodlebug hasn't already hunted
   if (!ateThisRound() && !getHasAttemptedMove())
   {
      Organism::move();
   }
}

///<summary>Attempt to breed if conditions allow</summary>
///<returns>Doodlebug* baby doodlebug<returns>
Doodlebug* Doodlebug::breed()
{
   Doodlebug* babyDoodlebug;
   IntTuple cellToBreedInto;
   int doodlebugAge = getAge();

   // Doodlebugs breed every 8 rounds
   if (doodlebugAge > 0
      && (doodlebugAge % DOODLEBUG_BREED_SPAN == 0))
   {
      babyDoodlebug = new Doodlebug();
   }
   else
   {
      babyDoodlebug = nullptr;
   }
   return babyDoodlebug;
}

///<summary>Get the type</summary>
///<returns>int, type (char value 'X' for Doodlebug)<returns>
int Doodlebug::getType()
{
   return Doodlebug::CHAR_DOODLEBUG;
}

///<summary>Determine if organism starves</summary>
///<returns>bool, true if Doodlebug has not eaten recently<returns>
bool Doodlebug::starve()
{
   int doodlebugAge = getAge();

   if (doodlebugAge - getLastAgeAte() >= DOODLEBUG_STARVE_SPAN)
   {
      return true;
   }
   return false;
}

///<summary>Determine if organism ate this round</summary>
///<returns>bool, true if Doodlebug ate this round<returns>
bool Doodlebug::ateThisRound()
{
   return getLastAgeAte() == getAge();
}
