/* 
 * File:   Hand.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 11:44 PM
 */

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:
    std::vector<Card*> cards; // Cards in the hand

public:
    Hand();                  // Default constructor
    ~Hand();                 // Destructor
    void addCard(Card* card); // Add a card to the hand
    void display() const;    // Display the hand
    bool hasCard(int value) const; // Check if a card with the value exists
    Card* removeCard(int value); // Remove a specific card by value
    int getCardCount() const;     // Get the count of cards in the hand
    bool isEmpty() const;         // Check if the hand is empty
    std::vector<std::pair<Card*, Card*> > findMatches() const; // Find matching pairs
};

#endif /* HAND_H */
