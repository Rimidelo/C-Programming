// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "Room.h"

class Dungeon
{
private:
    Room *startRoom;
    Room **rooms;
    int numRooms;

public:
    // Constructor
    Dungeon();

    // Destructor
    ~Dungeon();

    // Define the starting room of the dungeon
    void setStartRoom(Room *room);

     Room* getStartRoom() const {return startRoom;};

    // Add a room to the dungeon's rooms array
    void addRoom(Room *room);

    // Search for and return a room by its name
    Room *findRoom(const char *name);
};
