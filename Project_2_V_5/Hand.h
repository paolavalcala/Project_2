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
        ~Hand();                 // Destructor to clean up cards
        void addCard(Card* card); // Add a card to the hand
        void display() const;    // Display the hand
        std::vector<std::pair<Card*, Card*> > findMatches() const; //find matches
};

#endif /* HAND_H */
