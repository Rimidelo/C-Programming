#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Animal.hpp"
#include "ZooKeeper.hpp"

using namespace std;

class ZooKeeper;

class Enclosure
{
private:
    string species;
    Animal **animal_list; // list of animals
    int numOfAnimals; 
    ZooKeeper *assignedZooKeeper; //from the req i understand that for every enclosure can be one zookeeper but the same zookeeper can be on some enclosures

public:
    Enclosure(string species);
    ~Enclosure();
    Result AddAnimal(Animal *_animal);
    Result RemoveAnimal(Animal *_animal);
    Animal* FindAnimal(const string& name, const string& species);
    Result GetAnimals() const;
    int GetNumOfAnimals() const {return numOfAnimals;};
    const string GetEnclosureSpecies() const {return species;};
    //friend func
    friend Result ZooKeeper::AssignToEnclosure(Enclosure *enclosure);
};

