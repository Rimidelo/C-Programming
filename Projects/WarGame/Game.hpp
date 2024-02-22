// Vladimir Lihatchov 322017252
#pragma once
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Player.hpp"

using namespace std;

class Game {
private:
    Player player1;
    Player player2;
    Deck mainDeck;

public:
    // Constructor
    Game( Player &p1, Player &p2);
    // Copy constructor
    Game( Game& other);

    // Destructor
    ~Game();

    // Start the game
    void start();

    // Play a round of the game
    void playRound();

    // Check and return the winner of the game
    int checkWinner();
};