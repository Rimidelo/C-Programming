// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Item.h"

class Potion : public Item {
public:
    // Constructor
    Potion(const char *n, int h, int s, int d) : Item(n, h, s, d) {}

    // Destructor
    ~Potion() {}
};