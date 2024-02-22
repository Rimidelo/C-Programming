// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "Sword.h"
#include "Shield.h"
#include "potion.h"

class Monster; // Forward declaration to avoid circular dependencies
class Item;


class Room {
private:
    char* name;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Item* item;
    Monster* monster;

public:
    // Constructor
    Room(const char* n);

    // Destructor
    ~Room();

    // Connect rooms in different directions
    void connectNorth(Room* room);
    void connectSouth(Room* room);
    void connectEast(Room* room);
    void connectWest(Room* room);

    //getRoomName
    const char* getName() const {return name;};

    //get rooms:
    Room* getNorth(){return north;};
    Room* getSouth(){return south;};
    Room* getEast(){return east;};
    Room* getWest(){return west;};

    // Set item in the room
    void setItem(Item* i);

    //get item in the room
    Item* getItem(){return item;};

    // Set monster in the room
    void setMonster(Monster* m);

    //get monster in the room
    Monster* getMonster(){return monster;};
};
