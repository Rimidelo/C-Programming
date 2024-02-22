// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include "Card.hpp"


#define MAXCARDS 52
using namespace std;

class Deck
{
private:
    Card *cards[MAXCARDS];
    int cardCount;
public:
    Deck();
    // Copy constructor
    Deck(const Deck &other);
    // assignment operator
    Deck &operator=(const Deck &other);
    ~Deck();
    
    //get cardCount
    int GetCardCount() {return cardCount;};
    //shuffle
    void shuffle();
    //isEmpty
    bool isEmpty() const;
    //draw card
    Card draw();
    //add card not from file
    Result addCard(const Card &card);
    //populateDeckFromFile
    void populateDeckFromFile(const std::string& filename);
    //
    void printDeck() const;
};


