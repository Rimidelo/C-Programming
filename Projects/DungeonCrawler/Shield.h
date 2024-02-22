// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Item.h"

class Shield : public Item {
public:
    // Constructor
    Shield(const char *n, int h, int s, int d) : Item(n, h, s, d) {}

    // Destructor
    ~Shield() {}
};