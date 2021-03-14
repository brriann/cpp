
#include <cstdlib>

#include "Organism.h"
#include "Commons.cpp"

using std::srand;
using std::make_tuple;
using std::get;

/* -------------------------------------------------------------
CONSTANTS AND UTILITY VARIABLES
------------------------------------------------------------- */

const int DEFAULT_AGE = 0;
const bool DEFAULT_HAS_ATTEMPTED_MOVE = false;

// for safety, initialize organisms as 'outside of the 20x20 grid'
const int DEFAULT_LOCATION = 99;

const int MOVE_OPTIONS_COUNT = 4;

/* -------------------------------------------------------------
ORGANISM CLASS - MEMBER FUNCTION DEFINITIONS
------------------------------------------------------------- */

// Default Constructor
Organism::Organism()
{
   setAge(DEFAULT_AGE);
   setLastAgeAte(DEFAULT_AGE);
   setHasAttemptedMove(DEFAULT_HAS_ATTEMPTED_MOVE);
   setLocation(make_tuple(DEFAULT_LOCATION, DEFAULT_LOCATION));
}

///<summary>Organism constructor with location</summary>
///<param name="locationCtr">IntTuple, grid location to spawn Organism</param>
///<returns>Organism object<returns>
Organism::Organism(IntTuple locationCtr)
{
   setAge(DEFAULT_AGE);
   setLastAgeAte(DEFAULT_AGE);
   setHasAttemptedMove(DEFAULT_HAS_ATTEMPTED_MOVE);

   if (!setLocation(locationCtr))
   {
      setLocation(make_tuple(DEFAULT_LOCATION, DEFAULT_LOCATION));
   }
}

///<summary>Move, if possible, by updating location</summary>
void Organism::move()
{
   if (getHasAttemptedMove())
   {
      return;
   }

   setHasAttemptedMove(true);

   location = proposedLocation;
}

///<summary>Simple age mutator, increment by 1</summary>
void Organism::incrementAge()
{
   age++;
}

///<summary>Get the age</summary>
///<returns>int, age<returns>
int Organism::getAge()
{
   return age;
}

///<summary>Set the age</summary>
///<param name="ageToSet">int, age to set</param>
///<returns>bool, true if age was set<returns>
bool Organism::setAge(int ageToSet)
{
   if (ageToSet < 0)
   {
      return false;
   }

   age = ageToSet;
   return true;
}

///<summary>Get the last age at which Organism ate</summary>
///<returns>int, last age at which Organism ate<returns>
int Organism::getLastAgeAte()
{
   return lastAgeAte;
}

///<summary>Set the last age at which Organism ate</summary>
///<param name="lastAgeAteToSet">int, age to set</param>
///<returns>bool, true if lastAgeAte was set<returns>
bool Organism::setLastAgeAte(int lastAgeAteToSet)
{
   if (lastAgeAteToSet < 0)
   {
      return false;
   }

   lastAgeAte = lastAgeAteToSet;
   return true;
}

///<summary>Get hasAttemptedMove</summary>
///<returns>bool, hasAttemptedMove<returns>
bool Organism::getHasAttemptedMove()
{
   return hasAttemptedMove;
}

///<summary>Set hasAttemptedMove</summary>
///<param name="hasAttemptedMoveToSet">int, value to set</param>
///<returns>bool, true if value was set<returns>
bool Organism::setHasAttemptedMove(bool hasAttemptedMoveToSet)
{
   hasAttemptedMove = hasAttemptedMoveToSet;
   return true;
}

///<summary>Get the location of Organism</summary>
///<returns>IntTuple, location<returns>
IntTuple Organism::getLocation()
{
   return location;
}

///<summary>Set the location of Organism</summary>
///<param name="locationToSet">IntTuple, location to set</param>
///<returns>bool, true if value was set<returns>
bool Organism::setLocation(IntTuple locationToSet)
{
   // validation for location happens in client
   location = locationToSet;
   return true;
}

///<summary>Get the proposed location</summary>
///<returns>IntTuple, the proposed location<returns>
IntTuple Organism::getProposedLocation()
{
   // proposed location is used in move calculations
   return proposedLocation;
}

///<summary>Generate proposed location for Organism</summary>
void Organism::generateProposedLocation()
{
   // generate random  move direction
   MoveDirection moveDirection = 
      static_cast<MoveDirection>(rand() % MOVE_OPTIONS_COUNT);

   // calculate next cell from location
   IntTuple currentLocation = getLocation();
   IntTuple generatedLocation;

   switch (moveDirection)
   {
      case MoveDirection::UP:
         generatedLocation = 
            make_tuple(get<0>(currentLocation) - 1, get<1>(currentLocation));
         break;
      case MoveDirection::DOWN:
         generatedLocation = 
            make_tuple(get<0>(currentLocation) + 1, get<1>(currentLocation));
         break;
      case MoveDirection::LEFT:
         generatedLocation = 
            make_tuple(get<0>(currentLocation), get<1>(currentLocation) - 1);
         break;
      case MoveDirection::RIGHT:
         generatedLocation = 
            make_tuple(get<0>(currentLocation), get<1>(currentLocation) + 1);
         break;
   }

   proposedLocation = generatedLocation;
}
