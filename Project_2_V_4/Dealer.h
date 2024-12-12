/* 
 * File:   Dealer.h
 * Author: Paola Alcala
 *
 * Created on December 4, 2024, 6:16 PM
 */

#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "Deck.h"
#include "Hand.h"

class Dealer : public Player {
    private:
        Deck* deck;    // Deck managed by the dealer
        int nDeal;     // Number of cards dealt so far
    public:
        Dealer();              // Default constructor
        ~Dealer();             // Destructor to clean up the deck
        void shuffleDeck();    // Shuffle the deck
        Card* dealCard();      // Deal a single card
};

#endif /* DEALER_H */

