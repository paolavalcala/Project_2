/* 
 * File:   Player.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Hand.h"
#include "Deck.h"
using namespace std;

// Abstract base class Player
class Player {
protected:
    string name;             // Player name
    Hand hand;               // Player's hand
    static int totalScore;   // Shared among all players

public:
    Player(const string& name = "Anonymous") : name(name) {}
    virtual ~Player() {}     // Virtual destructor for polymorphism

    virtual void playTurn(Player& opponent, Deck& deck) = 0; // Pure virtual function

    string getName() const { return name; }
    Hand& getHand() { return hand; }

    // Static methods for score handling
    static void addToTotalScore(int score) { totalScore += score; }
    static int getTotalScore() { return totalScore; }
};

// Derived class HumanPlayer
class HumanPlayer : public Player {
public:
    HumanPlayer(const string& name) : Player(name) {}

    void playTurn(Player& opponent, Deck& deck);
};

// Derived class ComputerPlayer
class ComputerPlayer : public Player {
public:
    ComputerPlayer() : Player("Computer") {}

    void playTurn(Player& opponent, Deck& deck);
};

#endif /* PLAYER_H */

