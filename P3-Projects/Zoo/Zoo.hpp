#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Enclosure.hpp"
#include "ZooKeeper.hpp"


using namespace std;


class Zoo
{
private:
    Enclosure **Enclosure_list; // list of Enclosures
    int numOfEnclosures;
    // ZooKeeper **ZooKeeper_list;
    // int numOfZooKeepers;
    
public:
    Zoo();
    Result AddAnimal();
    Result RemoveAnimal();
    Result DispalyAnimals();
    int GetNumOfEnclosures() {return numOfEnclosures;};
    Enclosure* FindEnclosure(const string& species);
    ZooKeeper* CreateZookeeper(string _name);
    Result assignZooKeeper(ZooKeeper *_ZooKeeper,Enclosure *Enclosure);
    ~Zoo();
};


