/* 
 * File:   Deck.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
    private:
        int numCards;     // Number of cards in the deck
        int numDelt;      // Number of cards dealt so far
        Card** cards;     // Array of pointers to Card objects
    public:
        Deck(int numCards = 52); // Constructor with default 52 cards
        ~Deck();                // Destructor to free memory
        void display() const;   // Function to display the deck
        Card* getCard(int index) const; // Access a specific card
        void shuffle();         // Function to shuffle the deck
        int getCardCount() const; // Get the number of remaining cards in the deck
};

#endif /* DECK_H */

