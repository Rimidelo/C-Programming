// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Item
{
private:
    char *name;
    int healthBonus;
    int strengthBonus;
    int defenseBonus;

public:
    // Constructor
    Item(const char *n, int h, int s, int d);

    // Copy constructor
    Item(const Item &other);

    // Assignment operator
    Item &operator=(const Item &other);

    // Destructor
    ~Item();

    // Getter for item's name
    const char *getName() const;

    // Getter for health bonus
    int getHealthBonus() const;

    // Getter for strength bonus
    int getStrengthBonus() const;

    // Getter for defense bonus
    int getDefenseBonus() const;
};