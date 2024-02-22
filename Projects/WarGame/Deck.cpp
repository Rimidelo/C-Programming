// Vladimir Lihatchov 322017252
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include "Deck.hpp"

using namespace std;

//////////functions//////////////
// Constructor
Deck::Deck()
{
    for (int i = 0; i < MAXCARDS; i++)
    {
        cards[i] = new Card;
    }
    cardCount = 0;
}

// Copy constructor
Deck::Deck(const Deck &other)
{
    cardCount = other.cardCount;
    for (int i = 0; i < MAXCARDS; i++)
    {
        cards[i] = new Card;
        *cards[i] = *(other.cards[i]);
    }
}

// Assignment operator
Deck &Deck::operator=(const Deck &other)
{
    if (this != &other)
    {
        // Deallocate existing memory
        for (int i = 0; i < this->cardCount; i++)
        {
            delete cards[i];
        }

        // Allocate new memory and copy
        cardCount = other.cardCount;
        for (int i = 0; i < cardCount; i++)
        {
            cards[i] = new Card(*(other.cards[i]));
        }
    }
    return *this;
}
// Destructor
Deck::~Deck()
{
    for (int i = 0; i < MAXCARDS; i++)
    {
        delete cards[i];
    }
}

// Shuffle the cards in the deck
void Deck::shuffle()
{
    // Seed the random number generator
    std::random_device rd;
    std::mt19937 rng(rd());

    // Use std::shuffle to shuffle the cards array
    std::shuffle(cards, cards + MAXCARDS, rng);
}

// isEmpty
//  Implementation in Deck.cpp
bool Deck::isEmpty() const
{
    return (cardCount == 0);
}

Card Deck::draw()
{
    if (cardCount > 0)
    {
        // Decrement card count and return the top card
        return *(cards[--cardCount]);
    }
    else
    {
        // If the deck is empty, return a default-constructed card
        cout << "Deck is empty. Unable to draw a card." << endl;
        return Card();
    }
}

//add card not from file
Result Deck::addCard(const Card &card){
    // Check if there is space in the array to add the new card
    if (cardCount < MAXCARDS)
    {
        // Assign the new card to the deck at the current index
        cards[cardCount] = new Card(card);
        // Increment the card count
        cardCount++;
    }
    else
    {
        cout << "Deck is full. Unable to add a card." << std::endl;
        return Fail;
    }
    return Success;
}

void Deck::populateDeckFromFile(const string &filename)
{
    ifstream file(filename);
    string line;

    while (getline(file, line))
    {
        // Parse the line to extract suit and rank
        istringstream iss(line);
        string suitStr, rankStr;

        // Extract suit and rank using getline and comma as a delimiter
        if (getline(iss, suitStr, ',') && getline(iss, rankStr))
        {
            // Trim leading and trailing whitespaces from suit and rank
            suitStr.erase(suitStr.find_last_not_of(" \n\r\t") + 1);
            rankStr.erase(0, rankStr.find_first_not_of(" \n\r\t"));

            // Validate the extracted suit and rank 
            Suit suit = convertToSuit(suitStr);
            if (suit == DefaultCard)
            {
                std::cout << "Invalid suit: " << suitStr << ". Skipping line." << std::endl;
                continue;
            }

            // Create a new Card object inside the loop
            Card *newCard = new Card(suit, rankStr.c_str());
            // Check if there is space in the array to add the new card
            if (cardCount < MAXCARDS)
            {
                // Assign the new card to the deck at the current index
                cards[cardCount] = newCard;
                // cards[cardCount]->printCard(); //for debugging
                // Increment the card count
                cardCount++;
            }
            
        }
        else
        {
            std::cout << "Invalid line format: " << line << ". Skipping line." << std::endl;
        }
    }

    file.close();
}

//
void Deck::printDeck() const
{
    cout << cardCount << endl;
    for (int i = 0; i < cardCount; i++)
    {
        cards[i]->printCard();
    }
    
}