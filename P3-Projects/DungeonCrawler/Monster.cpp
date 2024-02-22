// Vladimir Lihatchov 322017252
#include "Character.h"
#include "Item.h"
#include "Monster.h"

using namespace std;

// Constructor
Monster::Monster(const char *n, int h, int s, int d) : health(h), strength(s), defense(d)
{
    name = strdup(n);
}

// Copy constructor
Monster::Monster(const Monster &other) : health(other.health), strength(other.strength), defense(other.defense)
{
    name = strdup(other.name);
}

// Assignment operator
Monster &Monster::operator=(const Monster &other)
{
    if (this != &other)
    {
        // Copy non-dynamic members
        health = other.health;
        strength = other.strength;
        defense = other.defense;

        // Free existing memory for name
        free(name);

        // Use strdup to allocate memory and copy the string
        name = strdup(other.name);
    }
    return *this;
}

// Destructor
Monster::~Monster()
{
    free(name);
}

// Attack a character
void Monster::attack(Character &target)
{
    int damageDealt = strength - target.getDefense();
    target.defend(damageDealt);
    // cout << name << " attacks " << target.getName() << " for " << damageDealt << " damage." << endl;
}

// Defend against incoming damage
void Monster::defend(int damage)
{
    int damageTaken = damage - defense;
    if (damageTaken > 0)
    {
        health -= damageTaken;
        // cout << name << " takes " << damageTaken << " damage." << endl;
    }
    else
    {
        // cout << name << " successfully defends the attack." << endl;
    }
}

// Check if the character is alive
bool Monster::isDefeated() const
{
    return health > 0;
}