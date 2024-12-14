
/* 
 * File:   main.cpp
 * Author: Paola Alcala
 *
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 5
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

        player1 = Player(player1Name);  // Set player 1's name
        player2 = Player(player2Name);  // Set player 2's name

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
    
    // Find matches for player 1
    std::vector<std::pair<Card*, Card*> > matches1 = hand1.findMatches();
    cout << "\nMatches for " << player1.getName() << ":\n";
    for (size_t i = 0; i < matches1.size(); i++) {
        cout << "Match: " << matches1[i].first->face() << " of " << matches1[i].first->suit()
             << " and " << matches1[i].second->face() << " of " << matches1[i].second->suit() << endl;
    }

    // Find matches for player 2
    std::vector<std::pair<Card*, Card*> > matches2 = hand2.findMatches();
    cout << "\nMatches for " << player2.getName() << ":\n";
    for (size_t i = 0; i < matches2.size(); i++) {
        cout << "Match: " << matches2[i].first->face() << " of " << matches2[i].first->suit()
             << " and " << matches2[i].second->face() << " of " << matches2[i].second->suit() << endl;
    }

    // Score tracking
    int player1Score = matches1.size();
    int player2Score = matches2.size();
    
    Player::addToTotalScore(player1Score + player2Score); // Update static score

    cout << "\nScores:\n";
    cout << player1.getName() << "'s Score: " << player1Score << endl;
    cout << player2.getName() << "'s Score: " << player2Score << endl;
    
    cout << "\nTotal Matches Across All Games: " << Player::getTotalScore() << endl;

    // Determine winner
    if (player1Score > player2Score) {
        cout << player1.getName() << " wins!\n";
    } else if (player2Score > player1Score) {
        cout << player2.getName() << " wins!\n";
    } else {
        cout << "It's a tie!\n";
    }
    
    return 0;
}




/*
 For Version 5 I will be working on comparing the cards in 
 each players hand to search for matches.
 * Compare the value of the card to each other
 
 function to find matches
 * 
 variable to hold cards that have matches for each player
 keep score of each match.
 * 
 * I will do this by adding a function to find matches in the hand class in Hand.h file.
 * Then I will update the Player class in Player.h to add a score tracker
 * to keep record of the matches found during the game.
  */





/// cloc /Users/paolaalcala/cis_17/CSC_CIS_17a/Project/Project2/Project_2_V_4