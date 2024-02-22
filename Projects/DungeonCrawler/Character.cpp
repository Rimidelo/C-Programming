// Vladimir Lihatchov 322017252
#include "Character.h"
#include "Item.h"
#include "Monster.h"

// Constructor
Character::Character(const char *n, int h, int s, int d) : health(h), strength(s), defense(d), currentRoom(nullptr),hasSword(0), hasShield(0), hasPotion(0)
{
    name = strdup(n);
}

// Copy constructor
Character::Character(const Character &other) : health(other.health), strength(other.strength), defense(other.defense), currentRoom(other.currentRoom),hasSword(other.hasSword), hasShield(other.hasShield), hasPotion(other.hasPotion)
{
    name = strdup(other.name);
}

// Assignment operator
Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        // Copy non-dynamic members
        health = other.health;
        strength = other.strength;
        defense = other.defense;
        currentRoom = other.currentRoom;
        hasPotion = other.hasPotion;
        hasShield = other.hasShield;
        hasSword = other.hasSword;

        // Free existing memory for name
        free(name);

        // Use strdup to allocate memory and copy the string
        name = strdup(other.name);
    }
    return *this;
}

// Destructor
Character::~Character()
{
    free(name);
}

// Attack a monster
void Character::attack(Monster &target)
{
    int damageDealt = strength - target.getDefense();
    target.defend(damageDealt);
    // cout << name << " attacks " << target.getName() << " for " << damageDealt << " damage." << endl;
}

// Defend against incoming damage
void Character::defend(int damage)
{
    int damageTaken = damage - defense;
    if (damageTaken > 0)
    {
        health -= damageTaken;
        // cout << name << " takes " << damageTaken << " damage." << std::endl;
    }
    else
    {
        // cout << name << " successfully defends the attack." << std::endl;
    }
}

// Check if the character is alive
bool Character::isAlive() const
{
    return health > 0;
}

// Overload + operator to apply item effects
Character &Character::operator+(const Item &item)
{
    // Apply item effects directly to the current character
    health += item.getHealthBonus();
    strength += item.getStrengthBonus();
    defense += item.getDefenseBonus();

    // cout << name << " gains ";
    // cout << item.getHealthBonus() << " health, ";
    // cout << item.getStrengthBonus() << " strength, and ";
    // cout << item.getDefenseBonus() << " defense from the item." << endl;
    stringToCorrectItem(item);

    return *this;
}

void Character::stringToCorrectItem(const Item &item){
    string itemName = item.getName();

    if (itemName == "Sword")
    {
        hasSword = 1;
    }
    else if (itemName == "Shield")
    {
        hasShield = 1;
    }
    else if (itemName == "Potion")
    {
        hasPotion = 1;
    }
}

//get inventory
string Character::printInventory(){
    string fullInventory;

    if (hasSword)
    {
        fullInventory += "Sword, ";
    }

    if (hasShield)
    {
        fullInventory += "Shield, ";
    }
    if (hasPotion)
    {
        fullInventory += "Potion ";
    }

    // Remove the trailing comma and space
    if (!fullInventory.empty())
    {
        fullInventory = fullInventory.substr(0, fullInventory.size() - 2);
    }

    return fullInventory;
}

