// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

enum Result
{
   Success,
   Fail
};

class Animal
{
private:
   string name;
   string species;
   int age;

public:
   // Constructor /Destructor
   Animal(const string& _name = "", const string&_species = "", int _age = 0);
   // Getters
   const string GetName() const {return name;};
   const string GetSpecies() const {return species;};
   int GetAge() const {return age;};
   Result DisplayDetails() const;
   //setters
   //no need right now, dont wanna change anything in the process
   ~Animal();
};

