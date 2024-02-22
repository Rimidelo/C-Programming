// Vladimir Lihatchov 322017252
#include <iostream>
#include <cstring>
#include <string>
#include "Room.h"

// Constructor
Room::Room(const char *n) : name(strdup(n)), north(nullptr), south(nullptr), east(nullptr), west(nullptr), item(nullptr), monster(nullptr)
{
}

// Destructor
Room::~Room()
{
    free(name);
}

// Connect rooms in different directions
void Room::connectNorth(Room *room)
{
    north = room;
}

void Room::connectSouth(Room *room)
{
    south = room;
}

void Room::connectEast(Room *room)
{
    east = room;
}

void Room::connectWest(Room *room)
{
    west = room;
}

// Set item in the room
void Room::setItem(Item *i)
{
    item = i;
}

// Set monster in the room
void Room::setMonster(Monster *m)
{
    monster = m;
}