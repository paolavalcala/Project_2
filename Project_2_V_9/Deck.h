/* 
 * File:   Deck.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
using namespace std;

class Dealer; // Forward declaration

class Deck {
private:
    int numCards;          // Number of cards in the deck
    int numDelt;           // Number of cards dealt
    vector<Card*> cards;   // Vector of pointers to Card objects

    friend class Dealer;   // Allow Dealer to access private members

public:
    Deck(int numCards = 52); // Constructor with default value
    ~Deck();                 // Destructor to free memory

    void display() const;    // Display the deck
    Card* getCard(int index) const; // Access a specific card
    void shuffle();          // Shuffle the deck
    int getCardCount() const { return numCards - numDelt; } // Remaining cards
};

#endif /* DECK_H */



