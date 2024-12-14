/* 
 * File:   Dealer.cpp
 * Author: Paola Alcala
 * 
 * Created on December 4, 2024, 6:16 PM
 */

#include "Dealer.h"

// Constructor: Initializes the dealer with a deck
Dealer::Dealer() : Player("Dealer"), nDeal(0) {
    deck = new Deck(52); // Default deck of 52 cards
}

// Destructor: Frees the deck memory
Dealer::~Dealer() {
    delete deck;
    deck = nullptr;    // Avoid dangling pointers
}

// Shuffle the deck
void Dealer::shuffleDeck() {
    deck->shuffle();
}

// Deal a single card
Card* Dealer::dealCard() {
    if (nDeal < 52) { // Ensure there are cards left to deal
        return deck->getCard(nDeal++);
    }
    return nullptr; // No cards left in the deck
}

bool Dealer::isDeckEmpty() const {
    return deck->getCardCount() == 0; // Deck is empty if no cards remain
}



