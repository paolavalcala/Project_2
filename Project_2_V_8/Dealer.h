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
    Deck* deck; // Pointer to the deck of cards
    int nDeal;  // Number of cards dealt so far

public:
    Dealer();               // Constructor
    ~Dealer();              // Destructor
    void shuffleDeck();     // Shuffle the deck
    Card* dealCard();       // Deal a card
    bool isDeckEmpty() const; // Check if the deck is empty

    void playTurn(Player& opponent, Deck& deck) override; // Implements abstract method
};

#endif /* DEALER_H */


