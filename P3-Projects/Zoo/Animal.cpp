// Vladimir Lihatchov 322017252
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Animal.hpp"

//
Animal::Animal(const string& _name, const string& _species, int _age)
{
   name = _name;
   species = _species;
   age = _age;
}

Result Animal::DisplayDetails() const {
   cout << "Animal Name: " << GetName() << ", Species: "<< GetSpecies() << ", Age: " << GetAge() << endl;
   return Success;
}

Animal::~Animal()
{
}
