// Vladimir Lihatchov 322017252
#include "Item.h"

// Constructor
Item::Item(const char *n, int h, int s, int d) : healthBonus(h), strengthBonus(s), defenseBonus(d)
{
    name = strdup(n);
}

// Copy constructor
Item::Item(const Item &other) : healthBonus(other.healthBonus), strengthBonus(other.strengthBonus), defenseBonus(other.defenseBonus)
{
    // Use strdup to allocate memory and copy the string
    name = strdup(other.name);
}

// Assignment operator
Item &Item::operator=(const Item &other)
{
    if (this != &other)
    {
        // Copy non-dynamic members
        healthBonus = other.healthBonus;
        strengthBonus = other.strengthBonus;
        defenseBonus = other.defenseBonus;

        // Free existing memory for name
        free(name);

        // Use strdup to allocate memory and copy the string
        name = strdup(other.name);
    }
    return *this;
}

// Destructor
Item::~Item()
{
    free(name);
}

// Getter for item's name
const char *Item::getName() const
{
    return name;
}

// Getter for health bonus
int Item::getHealthBonus() const
{
    return healthBonus;
}

// Getter for strength bonus
int Item::getStrengthBonus() const
{
    return strengthBonus;
}

// Getter for defense bonus
int Item::getDefenseBonus() const
{
    return defenseBonus;
}