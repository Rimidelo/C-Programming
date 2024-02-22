#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Enclosure.hpp"

using namespace std;

// Forward declaration
class Enclosure;

class ZooKeeper
{
private:
    string name;
    Enclosure **assignedEnclosures;
    int numOfEnclosuresOfkeeper;

public:
    ZooKeeper(const string &_name);
    ~ZooKeeper(); //not sure if to create because the destrctor of the 

    const string GetName() const { return name; };
    int GetNumOfEnclosures() const { return numOfEnclosuresOfkeeper; }
    Result AssignToEnclosure(Enclosure *enclosure);
};

