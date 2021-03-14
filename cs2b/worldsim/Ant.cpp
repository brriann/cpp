
#include "Ant.h"

/* -------------------------------------------------------------
CONSTANTS AND UTILITY VARIABLES
------------------------------------------------------------- */

const int ANT_BREED_SPAN = 3;

/* -------------------------------------------------------------
INITIALIZATION
------------------------------------------------------------- */

const char Ant::CHAR_ANT = 'o';

/* -------------------------------------------------------------
ANT CLASS - MEMBER FUNCTION DEFINITIONS
------------------------------------------------------------- */

// Default Constructor
Ant::Ant() : Organism()
{
   // deliberately empty
}

///<summary>Ant constructor with location</summary>
///<param name="locationCtr">IntTuple, grid location to spawn Ant</param>
///<returns>Ant object<returns>
Ant::Ant(IntTuple locationCtr) : Organism(locationCtr)
{
   // deliberately empty
}

///<summary>Attempt to breed if conditions allow</summary>
///<returns>Ant* baby ant<returns>
Ant* Ant::breed()
{
   Ant* babyAnt;
   IntTuple cellToBreedInto;
   int antAge = getAge();

   // Ants breed every 3 rounds
   if (antAge > 0
      && (antAge % ANT_BREED_SPAN == 0))
   {
      babyAnt = new Ant();
   }
   else
   {
      babyAnt = nullptr;
   }
   return babyAnt;
}

///<summary>Get the type</summary>
///<returns>int, type (char value 'o' for Ant)<returns>
int Ant::getType()
{
   return Ant::CHAR_ANT;
}

///<summary>Determine if organism starves</summary>
///<returns>bool, false, ants can't starve<returns>
bool Ant::starve()
{
   // ants cannot starve
   return false;
}

///<summary>Determine if organism ate this round</summary>
///<returns>bool, false, ants can't eat<returns>
bool Ant::ateThisRound()
{
   // ants cannot eat
   return false;
}
