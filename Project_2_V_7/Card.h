/* 
 * File:   Card.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:29 PM
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        unsigned char crdNum;
    public:
        Card(unsigned char);
        unsigned char suit();
        unsigned char face();
        unsigned char value();
};

#endif /* CARD_H */

