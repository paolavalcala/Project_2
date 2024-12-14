/* 
 * File:   Player.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Hand.h"
#include "Deck.h"

class Player {
protected:
    std::string name;
    Hand hand;
    static int totalScore; // Static variable shared among all players

public:
    Player(const std::string& name = "Anonymous") : name(name) {}
    virtual ~Player() {}

    virtual void playTurn(Player& opponent, Deck& deck) = 0; // Abstract method

    std::string getName() const { return name; }
    Hand& getHand() { return hand; }

    // Methods to handle total score
    static void addToTotalScore(int score) { totalScore += score; }
    static int getTotalScore() { return totalScore; }
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& name) : Player(name) {}

    void playTurn(Player& opponent, Deck& deck) override {
        int requestedValue;
        std::cout << getName() << ", enter a card value to request (1-10): ";
        std::cin >> requestedValue;

        if (opponent.getHand().hasCard(requestedValue)) {
            std::cout << opponent.getName() << " has the card! Transferring...\n";
            Card* transferredCard = opponent.getHand().removeCard(requestedValue);
            hand.addCard(transferredCard);
        } else {
            std::cout << opponent.getName() << " does not have the card. Go Fish!\n";
            if (deck.getCardCount() > 0) {
                Card* newCard = deck.getCard(deck.getCardCount() - 1);
                hand.addCard(newCard);
                std::cout << getName() << " drew a card.\n";
            } else {
                std::cout << "Deck is empty!\n";
            }
        }
    }
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer() : Player("Computer") {}

    void playTurn(Player& opponent, Deck& deck) override {
        int requestedValue = rand() % 10 + 1; // Random value between 1 and 10
        std::cout << getName() << " asks for card value: " << requestedValue << "\n";

        if (opponent.getHand().hasCard(requestedValue)) {
            std::cout << opponent.getName() << " has the card! Transferring...\n";
            Card* transferredCard = opponent.getHand().removeCard(requestedValue);
            hand.addCard(transferredCard);
        } else {
            std::cout << opponent.getName() << " does not have the card. Go Fish!\n";
            if (deck.getCardCount() > 0) {
                Card* newCard = deck.getCard(deck.getCardCount() - 1);
                hand.addCard(newCard);
                std::cout << getName() << " drew a card.\n";
            } else {
                std::cout << "Deck is empty!\n";
            }
        }
    }
};

#endif /* PLAYER_H */

