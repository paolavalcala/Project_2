/* 
 * File:   Player.h
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 7:30 PM
 */

#ifndef PLAYER_H
#define PLAYER_H


#include <string>
using namespace std;

class Player {
    protected:
        int id;
        string name;
    public:
        Player(string pName);  // Parameterized constructor
        Player();             // Default constructor
        string getName() const; // Getter for name
};

#endif /* PLAYER_H */
