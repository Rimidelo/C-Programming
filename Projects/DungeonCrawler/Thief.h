// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"

using namespace std;

class Thief : public Character
{
private:
    //nope
public:
    Thief(const char *n, int h, int s, int d) : Character(n,h,s,d){};
    ~Thief();
};

// Destructor
Thief::~Thief()
{
}