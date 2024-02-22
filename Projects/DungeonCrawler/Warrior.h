// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"

using namespace std;

class Warrior : public Character
{
private:
    //nope
public:
    Warrior(const char *n, int h, int s, int d) : Character(n,h,s,d){};
    ~Warrior();
};

// Destructor
Warrior::~Warrior()
{
}