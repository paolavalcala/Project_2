/* 
 * File:   Dealer.cpp
 * Author: Paola Alcala
 * 
 * Created on December 4, 2024, 6:16 PM
 */

#include "Dealer.h"
#include <iostream>
using namespace std;

// Constructor
Dealer::Dealer() : Player("Dealer"), deck(nullptr), nDeal(0) {
    deck = new Deck(52); // Dynamically allocate a new deck of 52 cards
}

// Destructor
Dealer::~Dealer() {
    delete deck; // Free the allocated deck memory
    deck = nullptr;
}

// Shuffle the deck
void Dealer::shuffleDeck() {
    if (deck) {
        deck->shuffle(); // Use Deck's public method
    }
}

// Deal a single card
Card* Dealer::dealCard() {
    if (deck && nDeal < deck->numCards) { // Directly access private member `numCards`
        return deck->cards[nDeal++];     // Directly access private member `cards`
    }
    return nullptr;
}

// Check if the deck is empty
bool Dealer::isDeckEmpty() const {
    return nDeal >= deck->numCards; // Directly access private member `numCards`
}

// Implement abstract playTurn method
void Dealer::playTurn(Player& opponent, Deck& deck) {
    cout << "Dealer does not participate in the game.\n";
}

