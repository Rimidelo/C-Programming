// Vladimir Lihatchov 322017252
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include "Game.h"

Game::Game() : characters(nullptr), numCharacters(0){};

// Destructor
Game::~Game()
{
    // Free memory for each room
    for (int i = 0; i < numCharacters; ++i)
    {
        delete characters[i];
    }
    // Free memory for the array of room pointers
    delete[] characters;
}

// Add a character to the game
void Game::addCharacter(Character *character)
{
    // Allocate memory for the array of character pointers
    Character **newCharacters = new Character *[numCharacters + 1];

    // Copy existing characters
    for (int i = 0; i < numCharacters; ++i)
    {
        newCharacters[i] = characters[i];
    }

    // Add the new character
    newCharacters[numCharacters] = character;

    // Update the characters array and count
    delete[] characters;
    characters = newCharacters;
    ++numCharacters;
}

// Search for and return a character by its name
Character *Game::findCharacter(const char *name)
{
    for (int i = 0; i < numCharacters; ++i)
    {
        if (strcmp(characters[i]->getName(), name) == 0)
        {
            return characters[i];
        }
    }
    return nullptr; // Room not found
}

// Move character to the next room based on direction
void Game::moveCharacter(Character *character, const string direction)
{
    Room *nextRoom = nullptr;

    // Determine the next room based on the direction
    if (direction == "North")
    {
        nextRoom = character->getCurrentRoom()->getNorth();
    }
    else if (direction == "South")
    {
        nextRoom = character->getCurrentRoom()->getSouth();
    }
    else if (direction == "East")
    {
        nextRoom = character->getCurrentRoom()->getEast();
    }
    else if (direction == "West")
    {
        nextRoom = character->getCurrentRoom()->getWest();
    }
    else
    {
        cout << "Invalid direction: " << direction << endl;
    }

    // Check if the next room is valid
    if (nextRoom)
    {
        // Update the character's current room
        character->setCurrentRoom(nextRoom);

        // Print the move message
        cout << character->getName() << " moves " << direction << " to " << nextRoom->getName() << "." << endl;
    }
    else
    {
        cout << "Invalid direction: " << direction << endl;
    }
}

// Function to convert a string command to the corresponding enum value
CommandType getCommandType(const string &command)
{
    if (command == "Create Character")
        return CREATE_CHARACTER;
    else if (command == "Create Room")
        return CREATE_ROOM;
    else if (command == "Set StartRoom")
        return SET_START_ROOM;
    else if (command == "Add Room")
        return ADD_ROOM;
    else if (command == "Connect")
        return CONNECT;
    else if (command == "Place Item")
        return PLACE_ITEM;
    else if (command == "Place Monster")
        return PLACE_MONSTER;
    else if (command == "Enter Dungeon")
        return ENTER_DUNGEON;
    else if (command == "Move")
        return MOVE;
    else if (command == "Fight")
        return FIGHT;
    else if (command == "PickUp")
        return PICKUP;
    else
        return UNKNOWN;
}

// Print to file all the stuff
void Game::outputFinalState(const char *filename)
{
    // Open the output file for writing
    ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    // Save the captured output to the file
    outputFile << buffer.str();

    // Close the file
    outputFile.close();
}
// Load commands from a file and execute them
void Game::loadFromFile(const char *filename)
{
    ifstream inputFile(filename); // open the file
    string line;                  // create a string type to hold the line
    // other stuff that dont like to be inside the switch
    string charName;
    string roomName;
    string setRoomName;
    string firstConnect, secondConncet, directionConnect;
    string itemName;
    string monsterName;
    int h, s, d;
    streambuf *originalCoutBuffer = cout.rdbuf(buffer.rdbuf());
    if (inputFile.is_open())
    { // while file is open
        while (getline(inputFile, line))
        {                            // while there are lines to read
            istringstream iss(line); // chagne string to stream
            string command;
            iss >> command;  // parse the stream into the first word
            string nextWord; // second word when needed
            string fullCommand;
            CommandType cmd;

            

            if (command == "Create" || command == "Set" || command == "Add" || command == "Place" || command == "Enter")
            {
                iss >> nextWord; // read the next word after "Create"
                // Concatenate the two words to form the full command
                fullCommand = command + " " + nextWord;
                cmd = getCommandType(fullCommand);
            }
            else
            {
                cmd = getCommandType(command);
            }

            // Switch based on the command type
            switch (cmd)
            {
            case CREATE_CHARACTER:
            {
                // Handle Create Character Logic
                int charHealth, charStrength, charDefense;
                iss >> charName >> charHealth >> charStrength >> charDefense;

                // Create a new character and add it to the game
                Character *newCharacter = new Character(charName.c_str(), charHealth, charStrength, charDefense);
                this->addCharacter(newCharacter);
                // // test
                // cout << "charater created succsesfully " << newCharacter->getName() << endl;
                break;
            }
            case CREATE_ROOM:
            {
                iss >> roomName;

                // Create a new room and add it to the game
                Room *newRoom = new Room(roomName.c_str());
                dungeon.addRoom(newRoom);
                // // test
                // cout << "room created succsesfully " << newRoom->getName() << endl;
                break;
            }
            case SET_START_ROOM:
            {
                iss >> setRoomName;
                dungeon.setStartRoom(dungeon.findRoom(setRoomName.c_str()));
                // // test
                // cout << "room set succsesfully " << dungeon.getStartRoom()->getName() << endl;
                break;
            }
            case ADD_ROOM:
            {
                // do nothing no need for duplicate code already did in create.
                break;
            }
            case CONNECT:
            {
                iss >> firstConnect >> secondConncet >> directionConnect;
                // Handle Connect Logic
                Room *firstRoom = dungeon.findRoom(firstConnect.c_str());
                Room *secondRoom = dungeon.findRoom(secondConncet.c_str());

                if (firstRoom != nullptr && secondRoom != nullptr)
                {
                    if (directionConnect == "North")
                    {
                        firstRoom->connectNorth(secondRoom);
                        secondRoom->connectSouth(firstRoom);
                    }
                    else if (directionConnect == "South")
                    {
                        firstRoom->connectSouth(secondRoom);
                        secondRoom->connectNorth(firstRoom);
                    }
                    else if (directionConnect == "East")
                    {
                        firstRoom->connectEast(secondRoom);
                        secondRoom->connectWest(firstRoom);
                    }
                    else if (directionConnect == "West")
                    {
                        firstRoom->connectWest(secondRoom);
                        secondRoom->connectEast(firstRoom);
                    }
                    else
                    {
                        // Handle unknown direction
                        cout << "Unknown direction: " << directionConnect << endl;
                    }
                    // cout << "here conncet" << endl;
                }
                else
                {
                    // Handle invalid room names
                    cout << "Invalid room names in CONNECT command" << endl;
                }
                break;
            }
            case PLACE_ITEM:
            {

                iss >> itemName >> roomName >> h >> s >> d;
                // Find the room in the dungeon
                Room *targetRoom = dungeon.findRoom(roomName.c_str());
                if (targetRoom != nullptr)
                {
                    // Check the type of item and create the corresponding subclass
                    Item *newItem = nullptr;
                    if (itemName == "Sword")
                    {
                        newItem = new Sword(itemName.c_str(), h, s, d);
                    }
                    else if (itemName == "Shield")
                    {
                        newItem = new Shield(itemName.c_str(), h, s, d);
                    }
                    else if (itemName == "Potion")
                    {
                        newItem = new Potion(itemName.c_str(), h, s, d);
                    }
                    else
                    {
                        // Handle unknown item type
                        cout << "Unknown item type in PLACE_ITEM command" << endl;
                        break;
                    }

                    // Place the item in the room
                    targetRoom->setItem(newItem);
                }
                else
                {
                    // Handle invalid room name
                    cout << "Invalid room name in PLACE_ITEM command" << endl;
                }
                // cout << "here item " << targetRoom->getItem()->getName() << " in " << targetRoom->getName() << endl;
                break;
            }
            case PLACE_MONSTER:
            {
                iss >> monsterName >> roomName >> h >> s >> d;

                // Find the room in the dungeon
                Room *targetRoom = dungeon.findRoom(roomName.c_str());

                if (targetRoom != nullptr)
                {
                    // Create a new monster and add it to the room
                    Monster *newMonster = new Monster(monsterName.c_str(), h, s, d);
                    targetRoom->setMonster(newMonster);
                }
                else
                {
                    // Handle invalid room name
                    cout << "Invalid room name in PLACE_MONSTER command" << endl;
                }
                // cout << "here monster" << endl;
                break;
            }
            case ENTER_DUNGEON:
            {
                iss >> charName;

                // Find the character by name
                Character *enteringCharacter = findCharacter(charName.c_str());

                if (enteringCharacter)
                {
                    // Set the current room of the character to the dungeon's start room
                    enteringCharacter->setCurrentRoom(dungeon.getStartRoom());
                    cout << enteringCharacter->getName() << " enters the dungeon." << endl;
                }
                else
                {
                    cout << "Character not found: " << charName << endl;
                }
                break;
            }
            case MOVE:
            {
                iss >> charName >> directionConnect;
                // Find the character by name
                Character *movingCharacter = findCharacter(charName.c_str());

                // Check if the character is found
                if (movingCharacter)
                {
                    moveCharacter(movingCharacter, directionConnect);
                }
                else
                {
                    cout << "Character not found: " << charName << endl;
                }
                break;
            }
            case FIGHT:
            {
                iss >> charName >> monsterName;
                // find character and monster:
                Character *character = findCharacter(charName.c_str());
                Room *currentRoom = character->getCurrentRoom();
                Monster *monster = currentRoom->getMonster();
                cout << charName << " fights " << monsterName << ": " << FightBetween(character, monster) << endl;
                break;
            }
            case PICKUP:
            {
                iss >> charName >> itemName;
                // Find character and item
                Character *character = findCharacter(charName.c_str());
                Room *currentRoom = character->getCurrentRoom();
                Item *item = currentRoom->getItem();

                if (item != nullptr)
                {
                    // Apply item effects to the character
                    (*character) + (*item);
                    cout << charName << " picks up " << itemName << "." << endl;
                }
                else
                {
                    cout << "No item to pick up in " << currentRoom->getName() << "." << endl;
                }
                break;
            }
            default:
            {
                // Handle unknown command type
                // cout << "Unknown command type: " << fullCommand << endl;
                break;
            }
            }
        }
        printFinalState();
        cout.rdbuf(originalCoutBuffer);
        inputFile.close();
        
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }
}

// fight function
string Game::FightBetween(Character *character, Monster *monster)
{
    string result;
    do
    {
        character->attack(*monster);
        monster->attack(*character);

    } while (character->isAlive() && monster->isDefeated());

    if (character->isAlive())
    {
        result = "Victory";
    }
    else
    {
        result = "Lose";
    }
    return result;
}

// print final state
void Game::printFinalState()
{
    for (int i = 0; i < numCharacters; i++)
    {
        Character *ch = characters[i];
        cout << "\n"
             << ch->getName() << "'s Final Stats:"
             << "\nHealth: " << ch->getHealth() << "\nStrength: " << ch->getStrength() << "\nDefense: " << ch->getDefense() << "\nInventory: " << ch->printInventory() << endl;
    }
}
