
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 1
 */

//System Libraries
#include <iostream> // Input-Output Library
#include "Dealer.h"

#include "Player.h"
#include "Deck.h"

using namespace std;

int main(int argc, char** argv) {
    
    // Declare players outside the conditional blocks
    Player player1;
    Player player2;
    
    // Prompt for game mode
    int choice;
    cout << "Choose game mode:\n";
    cout << "1. Two Players\n";
    cout << "2. Play against the Computer\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear input buffer for getline()

    if (choice == 1) {
        // Two players
        string player1Name, player2Name;
        cout << "Enter Player 1's name: ";
        getline(cin, player1Name);
        cout << "Enter Player 2's name: ";
        getline(cin, player2Name);

        Player player1(player1Name);
        Player player2(player2Name);

        cout << "\nWelcome " << player1.getName() << " and " << player2.getName() << "!\n";
    } else if (choice == 2) {
        // Player vs Computer
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);

        player1 = Player(playerName);
        player2 = Player("Computer");

        cout << "\nWelcome " << player1.getName() << "! You will be playing against " << player2.getName() << ".\n";
    } else {
        cout << "Invalid choice. Exiting program.\n";
        return 0;
    }

    // Create a deck
    Deck deck(52);
    cout << "\nDeck of Cards:\n";
    deck.display();
    
    // Shuffle the deck
    cout << "\nShuffling Deck...\n";
    deck.shuffle();

    cout << "\nShuffled Deck:\n";
    deck.display();
    
    // Dealer setup
    Dealer dealer;
    dealer.shuffleDeck();
    
    // Deal cards to each player
    Hand hand1, hand2;
    for (int i = 0; i < 5; i++) { // Each player gets 5 cards
        hand1.addCard(dealer.dealCard());
        hand2.addCard(dealer.dealCard());
    }
    
    
    // Display hands
    cout << "\n" << player1.getName() << "'s Hand:\n";
    hand1.display();

    cout << "\n" << player2.getName() << "'s Hand:\n";
    hand2.display();
    

    
    return 0;
}




/*
 For Version 4 I will be creating a dealer structure and cpp file.
 I will be connecting the the player, hand and dealer files so I can deal 
 cards to each player. 
  */





/// cloc /Users/paolaalcala/cis_17/CSC_CIS_17a/Project/Project2/Project_2_V_4