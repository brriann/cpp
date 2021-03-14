#pragma once

#ifndef Organism_h
#define Organism_h

#include "Commons.cpp";

class Organism
{
public:
   Organism();
   Organism(IntTuple);
   virtual void move();
   void incrementAge();
   int getAge();
   bool setAge(int);
   virtual int getLastAgeAte();
   virtual bool setLastAgeAte(int);
   bool getHasAttemptedMove();
   bool setHasAttemptedMove(bool);
   IntTuple getLocation();
   bool setLocation(IntTuple);
   IntTuple getProposedLocation();
   void generateProposedLocation();
   virtual Organism* breed() = 0;
   virtual int getType() = 0;
   virtual bool starve() = 0;
   virtual bool ateThisRound() = 0;
private:
   int age;
   int lastAgeAte;
   bool hasAttemptedMove;
   IntTuple location;
   IntTuple proposedLocation;
};

#endif // Organism_h