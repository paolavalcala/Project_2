/* 
 * File:   Dealer.cpp
 * Author: Paola Alcala
 * 
 * Created on December 4, 2024, 6:16 PM
 */

#include "Dealer.h"
#include <iostream>

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
        deck->shuffle();
    }
}

// Deal a single card
Card* Dealer::dealCard() {
    if (nDeal < deck->getCardCount()) {
        return deck->getCard(nDeal++);
    }
    return nullptr; // Return nullptr if no cards remain
}

// Check if the deck is empty
bool Dealer::isDeckEmpty() const {
    return nDeal >= deck->getCardCount();
}

// Implement abstract playTurn method
void Dealer::playTurn(Player& opponent, Deck& deck) {
    // Dealers typically do not play a turn. Could be left empty or used for automation.
    std::cout << "Dealer does not participate in the game.\n";
}





