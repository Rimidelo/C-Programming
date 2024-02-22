// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

class Monster; // Forward declaration to avoid circular dependencies
class Item;
class Room;

class Character
{
protected:
    char *name;
    int health;
    int strength;
    int defense;
    Room *currentRoom;
    int hasSword;
    int hasShield;
    int hasPotion;


public:
    // Constructor
    Character(const char *n, int h, int s, int d);

    // Copy constructor
    Character(const Character &other);

    // Assignment operator
    Character &operator=(const Character &other);

    // Destructor
    ~Character();

    //get strengh
    int getStrength(){return strength;};

    // Attack a monster
    void attack(Monster &target);

    // Defend against incoming damage
    void defend(int damage);

    // Check if the character is alive
    bool isAlive() const;

    // Overload + operator to apply item effects
    Character &operator+(const Item &item);

    // getDefence
    int getDefense() { return defense; };

    // Getter for the name
    const char *getName() const { return name; }

    // Getter for currentRoom
    Room *getCurrentRoom() const{return currentRoom;}

    //get health
    int getHealth(){return health;};

    //get defense
    int getDefence(){return defense;};

    // Setter for currentRoom
    void setCurrentRoom(Room *room){currentRoom = room;}

    // Setters for item flags
    void setHasSword(int value) { hasSword = value; }
    void setHasShield(int value) { hasShield = value; }
    void setHasPotion(int value) { hasPotion = value; }
    // add more setters for other item categories as needed

    // Getters for item flags
    int getHasSword() const { return hasSword; }
    int getHasShield() const { return hasShield; }
    int getHasPotion() const { return hasPotion; }

    //deal with items
    void stringToCorrectItem(const Item &item);
    string printInventory();
};