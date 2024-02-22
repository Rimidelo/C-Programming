// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"

using namespace std;

class Mage : public Character
{
private:
    //nope
public:
    Mage(const char *n, int h, int s, int d) : Character(n,h,s,d){};
    ~Mage();
};

// Destructor
Mage::~Mage()
{
}