// Vladimir Lihatchov 322017252
#include "Card.hpp"

using namespace std;

Card::Card()
{
    suit = DefaultCard;
    rank = nullptr;
}

Card::Card(Suit s, const char *r)
{
    suit = s;
    rank = strdup(r);
    if (rank == nullptr)
    {
        cout << "Memory allocation failed in Card constructor - constructor" << endl;
    }
};

// Copy constructor
Card::Card(const Card &other)
{
    suit = other.suit;
    rank = strdup(other.rank);
    if (rank == nullptr)
    {
        cout << "Memory allocation failed in Card constructor - copy constructor" << endl;
    }
};

// assignment operator
Card &Card::operator=(const Card &other)
{
    if (this != &other) // Check for self-assignment
    {
        // Copy suit
        suit = other.suit;
        // Release existing memory for rank
        free(rank);
        // Allocate memory for rank and copy the rank from the other card
        rank = strdup(other.rank);
        if (other.rank != nullptr)
        {
            if (rank == nullptr)
            {
                cout << "Memory allocation failed in Card constructor - operator constractor" << endl;
            }
        }
    }
    return *this;
}
// Destructor
Card::~Card()
{
    free(rank);
}

// Setter for suit
void Card::setSuit(Suit s)
{
    suit = s;
}

// Setter for rank
void Card::setRank(const char *r)
{
    // Release existing memory for rank
    free(rank);
    rank = strdup(r);
}

// Implementation in Card.cpp
void Card::printCard() const
{
    cout << "Suit: ";
    switch (suit)
    {
    case Hearts:
        cout << "Hearts";
        break;
    case Spades:
        cout << "Spades";
        break;
    case Diamonds:
        cout << "Diamonds";
        break;
    case Clubs:
        cout << "Clubs";
        break;
    default:
        cout << "Unknown";
    }

    cout << " Rank: " << rank << endl;
}

// Implementation of the free-standing function
Suit convertToSuit(const string &suitStr)
{
    if (suitStr == "Hearts")
        return Hearts;
    else if (suitStr == "Spades")
        return Spades;
    else if (suitStr == "Diamonds")
        return Diamonds;
    else if (suitStr == "Clubs")
        return Clubs;
    else
        return DefaultCard;
}

// Convert rank to int for comparing in the game
int convertRankToInt(const char *rank)
{
    if (strcmp(rank, "2") == 0)
    {
        return 2;
    }
    else if (strcmp(rank, "3") == 0)
    {
        return 3;
    }
    else if (strcmp(rank, "4") == 0)
    {
        return 4;
    }
    else if (strcmp(rank, "5") == 0)
    {
        return 5;
    }
    else if (strcmp(rank, "6") == 0)
    {
        return 6;
    }
    else if (strcmp(rank, "7") == 0)
    {
        return 7;
    }
    else if (strcmp(rank, "8") == 0)
    {
        return 8;
    }
    else if (strcmp(rank, "9") == 0)
    {
        return 9;
    }
    else if (strcmp(rank, "10") == 0)
    {
        return 10;
    }
    else if (strcmp(rank, "jack") == 0)
    {
        return 11;
    }
    else if (strcmp(rank, "Queen") == 0)
    {
        return 12;
    }
    else if (strcmp(rank, "King") == 0)
    {
        return 13;
    }
    else if (strcmp(rank, "Ace") == 0)
    {
        return 1; // Ace is 1
    }
    else
    {
        // Invalid rank
        return -1;
    }
}
// compare ranks
int compareRanks(const Card &p1, const Card &p2)
{
    int rank1 = convertRankToInt(p1.getRank());
    int rank2 = convertRankToInt(p2.getRank());

    if (rank1 > rank2)
    {
        return 1; // Player 1 wins
    }
    else if (rank1 < rank2)
    {
        return 2; // Player 2 wins
    }
    else
    {
        return 0; // It's a tie
    }
}
