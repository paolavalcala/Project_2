/* 
 * File:   Player.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:30 PM
 */

#include "Player.h"
#include <iostream>
using namespace std;

int Player::totalScore = 0; // Initialize static member

// HumanPlayer's playTurn implementation
void HumanPlayer::playTurn(Player& opponent, Deck& deck) {
    int requestedValue;
    cout << getName() << ", enter a card value to request (1-10): ";
    cin >> requestedValue;

    if (opponent.getHand().hasCard(requestedValue)) {
        cout << opponent.getName() << " has the card! Transferring...\n";
        Card* transferredCard = opponent.getHand().removeCard(requestedValue);
        hand.addCard(transferredCard);
    } else {
        cout << opponent.getName() << " does not have the card. Go Fish!\n";
        if (deck.getCardCount() > 0) {
            Card* newCard = deck.getCard(deck.getCardCount() - 1);
            hand.addCard(newCard);
            cout << getName() << " drew a card.\n";
        } else {
            cout << "Deck is empty!\n";
        }
    }
}

// ComputerPlayer's playTurn implementation
void ComputerPlayer::playTurn(Player& opponent, Deck& deck) {
    int requestedValue = rand() % 10 + 1; // Random value between 1 and 10
    cout << getName() << " asks for card value: " << requestedValue << "\n";

    if (opponent.getHand().hasCard(requestedValue)) {
        cout << opponent.getName() << " has the card! Transferring...\n";
        Card* transferredCard = opponent.getHand().removeCard(requestedValue);
        hand.addCard(transferredCard);
    } else {
        cout << opponent.getName() << " does not have the card. Go Fish!\n";
        if (deck.getCardCount() > 0) {
            Card* newCard = deck.getCard(deck.getCardCount() - 1);
            hand.addCard(newCard);
            cout << getName() << " drew a card.\n";
        } else {
            cout << "Deck is empty!\n";
        }
    }
}