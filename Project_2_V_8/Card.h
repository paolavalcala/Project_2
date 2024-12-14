/* 
 * File:   Card.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:29 PM
 */

#ifndef CARD_H
#define CARD_H

#include <iostream> // For stream insertion operator

class Card {
private:
    unsigned char crdNum; // Card number (0-51)

public:
    Card(unsigned char n = 0); // Constructor with default value
    Card(const Card& other);   // Copy constructor

    unsigned char suit() const;
    unsigned char face() const;
    unsigned char value() const;

    // Overloaded operators
    bool operator==(const Card& other) const; // Equality
    bool operator!=(const Card& other) const; // Inequality
    Card& operator=(const Card& other);       // Assignment
    friend std::ostream& operator<<(std::ostream& os, const Card& card); // Stream insertion
};

#endif /* CARD_H */



