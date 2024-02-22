// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

enum Result
{
    Success,
    Fail
};

enum Suit
{
    DefaultCard,
    Hearts,
    Spades,
    Diamonds,
    Clubs,
};
// Suit suitFromChar(string s);
class Card
{
private:
    Suit suit;
    char *rank;

public:
    Card();
    Card(Suit s, const char *r);
    // Copy constructor
    Card(const Card &other);
    // assignment operator
    Card &operator=(const Card &other);
    // Getter for suit
    Suit getSuit() const { return suit; };
    // Getter for rank
    const char* getRank() const { return rank; }
    // Setter for suit
    void setSuit(Suit s);
    // Setter for rank
    void setRank(const char *r);
    //print card for debugging and stuff
    void printCard() const;
    //convert rank to int for comparing
    int convertRankToInt(const char* rank);
    ~Card();
};

Suit convertToSuit(const string& suitStr);
//compare ranks
int compareRanks(const Card &p1, const Card &p2);