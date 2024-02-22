// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Deck.hpp"
using namespace std;

//dont forget to check for null
//dont forget to realse memory when neeeded
//give meanigfull names to the variables
//cooments above every func that shows what it does
//use copy constrcutro and assgnmet operator

class Player {
private:
    char* name;
    Deck hand;

public:
    // Constructor to initialize a player with a name
    Player(const char* n);

    // Copy constructor for deep copying of player objects
    Player(const Player& other);

    //ass opp
    Player& operator=(const Player& other);

    // Destructor to free allocated memory
    ~Player();  

    // Adds a card to the player's hand
    Result receiveCard(const Card &card);

    // Plays and returns a card from the player's hand
    Card playCard();

    //show deck test
    Result PrintPlayersDeck() const;
    //check how many cards in the hand
    int getDeckSize(){return hand.GetCardCount();};
};