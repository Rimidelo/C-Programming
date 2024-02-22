// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Item.h"

class Sword : public Item {
public:
    // Constructor
    Sword(const char *n, int h, int s, int d) : Item(n, h, s, d) {}

    // Destructor
    ~Sword() {}
};