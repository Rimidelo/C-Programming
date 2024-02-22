// Vladimir Lihatchov 322017252
#include "Player.hpp"
using namespace std;

// Constructor to initialize a player with a name
Player::Player(const char* n) : name(nullptr) {
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
}


// Copy constructor for deep copying of player objects
Player::Player(const Player& other) : name(nullptr), hand(other.hand) {
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
}

//assigmnet operator
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        // Copy the name
        delete[] name;
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }

        // Perform deep copy of the hand
        hand = other.hand;
    }
    return *this;
}


// Add a card to the player's hand
Result Player::receiveCard(const Card &card)
{
    hand.addCard(card);
    return Success;
}

// Plays and returns a card from the player's hand
Card Player::playCard()
{
    return hand.draw();
}

// Destructor to free allocated memory
Player::~Player() {
    delete[] name;
    // The Deck destructor will automatically be called for the 'hand' member.
}

Result Player::PrintPlayersDeck() const{
    hand.printDeck();
    return Success;
}