// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include "Character.h"
#include "Monster.h"
#include "Item.h"
#include "Room.h"
#include "Dungeon.h"

using namespace std;

enum CommandType {

    CREATE_CHARACTER,
    CREATE_ROOM,
    SET_START_ROOM,
    ADD_ROOM,
    CONNECT,
    PLACE_ITEM,
    PLACE_MONSTER,
    ENTER_DUNGEON,
    MOVE,
    FIGHT,
    PICKUP,
    UNKNOWN
};

class Game
{
private:
    Dungeon dungeon;
    Character **characters; // Dynamic array of characters
    int numCharacters;     // Number of characters
    ostringstream buffer;  // Custom buffer to capture cout output

public:
    // Constructor
    Game();

    //des
    ~Game();
    // Add a character to the game
    void addCharacter(Character *character);

    // Search for and return a character by its name
    Character *findCharacter(const char *name);

    //fight function
    string FightBetween(Character *character,Monster *monster);

    // Load commands from a file and execute them
    void loadFromFile(const char *filename);

    //Print to file all the stuff
    void outputFinalState(const char *filename);

    // Execute loaded commands
    void executeCommands(){};

    // Move character to the next room based on direction
    void moveCharacter(Character *character, const string direction);

    //print final state
    void printFinalState();
};

CommandType getCommandType(const string& command);
