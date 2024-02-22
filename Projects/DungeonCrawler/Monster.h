// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"

class Character; // Forward declaration to avoid circular dependencies

class Monster
{
protected:
    char *name;
    int health;
    int strength;
    int defense;

public:
    // Constructor
    Monster(const char *n, int h, int s, int d);

    // Copy constructor
    Monster(const Monster &other);

    // Assignment operator
    Monster &operator=(const Monster &other);

    // Destructor
    ~Monster();

    //get strengh
    int getStrength(){return strength;};

    // Attack a character
    void attack(Character &target);

    // defend against and attack
    void defend(int damage);

    // Check if the monster is defeated
    bool isDefeated() const;

    // getDefence
    int getDefense() { return defense; };

    // Getter for the name
    const char *getName() const { return name; }
};
