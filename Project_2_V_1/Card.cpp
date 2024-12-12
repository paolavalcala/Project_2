/* 
 * File:   Card.cpp
 * Author: Paola Alcala
 * 
 * Created on December 3, 2024, 7:29 PM
 */

#include "Card.h"

Card::Card(unsigned char n){
    crdNum=n%52;
}
        
unsigned char Card::suit(){
    char s[]={'S','D','C','H'}; //Spade, Diamond, Clubs, Heart
    unsigned char suitN=crdNum/13;
    return s[suitN];
}
        
unsigned char Card::face(){
    char f[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    unsigned char faceN=crdNum%13;
    return f[faceN];
}
        
unsigned char Card::value(){
    unsigned char n=crdNum%13;
    n++;
    return n>13?13:n; // decides the value to return based on the value of n 
}

