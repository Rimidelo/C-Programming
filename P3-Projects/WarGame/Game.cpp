// Vladimir Lihatchov 322017252
#include "Game.hpp"
using namespace std;

Game::Game(Player &p1,Player &p2) : player1(p1), player2(p2) 
{
}

// copy constructor
Game::Game(Game &other) : player1(other.player1), player2(other.player2), mainDeck(other.mainDeck)
{
}

Game::~Game()
{
    // Destructor code if needed
}

void Game::start()
{
    // what is the point of this func
    cout << "Game Starting!" << endl;
}

void Game::playRound()
{
    // cout << "lets check things:"<<endl;
    // player1.PrintPlayersDeck();
    // player2.PrintPlayersDeck();
    // cout << "main deck: "<< endl;
    // mainDeck.printDeck();
    Card player1Card = player1.playCard();
    Card player2Card = player2.playCard();

    // put the cards on the field
    mainDeck.addCard(player1Card);
    mainDeck.addCard(player2Card);
    // //print for checks:
    // cout << "main deck in middle of round" << endl;
    // mainDeck.printDeck();
    // Use the compareRanks function
    int result = compareRanks(player1Card, player2Card);
    if (result == 1)
    {
        // Player 1 wins
        while (mainDeck.GetCardCount() != 0)
        {
            player1.receiveCard(mainDeck.draw());
        }
        // cout << "Player 1 wins this round!" << endl;
    }
    else if (result == 2)
    {
        // Player 2 wins
        while (mainDeck.GetCardCount() != 0)
        {
            player2.receiveCard(mainDeck.draw());
        }
        // cout << "Player 2 wins! this round" << endl;
        return;
    }
    else
    {
        // It's a tie
        // cout << "Initiate war" << endl;
        // case where the war starts but one player is out of cards
        if (this->checkWinner() == 1)
        {
            while (mainDeck.GetCardCount() != 0)
            {
                player1.receiveCard(mainDeck.draw());
                return;
            }
        }
        else if (this->checkWinner() == 2)
        {
            while (mainDeck.GetCardCount() != 0)
            {
                player2.receiveCard(mainDeck.draw());
            }
        }
        mainDeck.addCard(player1.playCard());
        mainDeck.addCard(player2.playCard());
        // case where after the giving of card to deck in war one player is out of cards
        if (this->checkWinner() == 1)
        {
            while (mainDeck.GetCardCount() != 0)
            {
                player1.receiveCard(mainDeck.draw());
            }
        }
        else if (this->checkWinner() == 2)
        {
            while (mainDeck.GetCardCount() != 0)
            {
                player2.receiveCard(mainDeck.draw());
            }
        }
        else{
            playRound();
        }
    }
    //
}

int Game::checkWinner()
{
    if (player1.getDeckSize() == 0)
    {
        return 2; // Player 2 wins
    }
    else if (player2.getDeckSize() == 0)
    {
        return 1; // Player 1 wins
    }
    else
    {
        return 0; // Game still ongoing
    }
}