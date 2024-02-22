// Vladimir Lihatchov 322017252
#include <iostream>
#include <cstring>
#include <string>
#include "Dungeon.h"

// Constructor
Dungeon::Dungeon() : startRoom(nullptr), rooms(nullptr), numRooms(0)
{
}

// Destructor
Dungeon::~Dungeon()
{
    // Free memory for each room
    for (int i = 0; i < numRooms; ++i)
    {
        delete rooms[i];
    }
    // Free memory for the array of room pointers
    delete[] rooms;
}

// Define the starting room of the dungeon
void Dungeon::setStartRoom(Room *room)
{
    startRoom = room;
}

// Add a room to the dungeon's rooms array
void Dungeon::addRoom(Room *room)
{
    // Allocate memory for the array of room pointers
    Room **newRooms = new Room *[numRooms + 1];

    // Copy existing rooms
    for (int i = 0; i < numRooms; ++i)
    {
        newRooms[i] = rooms[i];
    }

    // Add the new room
    newRooms[numRooms] = room;

    // Update the rooms array and count
    delete[] rooms;
    rooms = newRooms;
    ++numRooms;
}

// Search for and return a room by its name
Room *Dungeon::findRoom(const char *name)
{
    for (int i = 0; i < numRooms; ++i)
    {
        if (strcmp(rooms[i]->getName(), name) == 0)
        {
            return rooms[i];
        }
    }
    return nullptr; // Room not found
}