/* 
 * File:   main.cpp
 * Author: Paola Alcala
 * Created on December 3, 2024, 6:38 PM
 * Purpose: Project 2 Version 9
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"
#include "Hand.h"
#include "Card.h"
using namespace std;

// Function prototypes
void displayScores(Player* players[], const Hand matchesDecks[], int numPlayers);
void announceWinner(Player* players[], const Hand matchesDecks[], int numPlayers);
void checkInitialMatches(Player& player, Hand& hand, Hand& matchesDeck);

// Template function to find maximum score (Using templates)
template <typename T>
T findMaxScore(const T* scores, int size) {
    T max = scores[0];
    for (int i = 1; i < size; ++i) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    return max;
}

// Exception class for invalid card requests
class InvalidCardRequest : public exception {
public:
    const char* what() const throw() {
        return "Invalid card value requested.";
    }
};

int main(int argc, char** argv) {
    // Array of player pointers (Demonstrating aggregation)
    Player* players[2];
    Hand hands[2], matchesDecks[2];
    const int numPlayers = 2;

    // Game mode selection
    int choice;
    cout << "Choose game mode:\n1. Two Players\n2. Play against the Computer\nEnter your choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        string player1Name, player2Name;
        cout << "Enter Player 1's name: ";
        getline(cin, player1Name);
        cout << "Enter Player 2's name: ";
        getline(cin, player2Name);
        players[0] = new HumanPlayer(player1Name);
        players[1] = new HumanPlayer(player2Name);
    } else if (choice == 2) {
        string playerName;
        cout << "Enter your name: ";
        getline(cin, playerName);
        players[0] = new HumanPlayer(playerName);
        players[1] = new ComputerPlayer();
    } else {
        cout << "Invalid choice. Exiting.\n";
        return 0;
    }

    Deck deck(52); // Instantiate a deck object (aggregation)
    deck.shuffle();
    Dealer dealer;

    // Initial deal of cards
    cout << "\nDealing cards to players...\n";
    for (int i = 0; i < 5; i++) {
        hands[0].addCard(dealer.dealCard());
        hands[1].addCard(dealer.dealCard());
    }

    // Display initial hands
    for (int i = 0; i < numPlayers; ++i) {
        cout << players[i]->getName() << "'s Hand:\n";
        hands[i].display();
    }

    // Check for initial matches
    cout << "\nChecking for initial matches...\n";
    for (int i = 0; i < numPlayers; ++i) {
        checkInitialMatches(*players[i], hands[i], matchesDecks[i]);
    }

    // Game loop
    bool gameActive = true;
    int currentPlayerIndex = 0;

    while (gameActive) {
        Player& currentPlayer = *players[currentPlayerIndex];
        Hand& currentHand = hands[currentPlayerIndex];
        Hand& opponentHand = hands[1 - currentPlayerIndex];
        Hand& currentMatchesDeck = matchesDecks[currentPlayerIndex];

        cout << "\n" << currentPlayer.getName() << "'s turn.\nYour hand:\n";
        currentHand.display();

        int requestedValue;
        try {
            if (dynamic_cast<ComputerPlayer*>(&currentPlayer)) {
                requestedValue = rand() % 10 + 1;
                cout << currentPlayer.getName() << " asks for card value: " << requestedValue << "\n";
            } else {
                cout << "Ask for a card value (1-10): ";
                cin >> requestedValue;
                if (requestedValue < 1 || requestedValue > 10) {
                    throw InvalidCardRequest();
                }
            }
        } catch (const InvalidCardRequest& e) {
            cout << e.what() << "\nTurn forfeited.\n";
            currentPlayerIndex = 1 - currentPlayerIndex; // Switch turns
            continue;
        }

        if (opponentHand.hasCard(requestedValue)) {
            cout << players[1 - currentPlayerIndex]->getName() << " has the card! Transferring...\n";
            Card* transferredCard = opponentHand.removeCard(requestedValue);
            currentHand.addCard(transferredCard);

            // Check for matches
            vector<pair<Card*, Card*> > newMatches = currentHand.findMatches();
            for (size_t i = 0; i < newMatches.size(); ++i) {
                currentMatchesDeck.addCard(newMatches[i].first);
                currentMatchesDeck.addCard(newMatches[i].second);
                currentHand.removeCard(newMatches[i].first->value());
                currentHand.removeCard(newMatches[i].second->value());
            }
            cout << "\nMatches found this turn:\n";
            currentMatchesDeck.display();
            displayScores(players, matchesDecks, numPlayers);
            continue; // Player gets another turn
        } else {
            cout << players[1 - currentPlayerIndex]->getName() << " does not have the card. Go Fish!\n";
            Card* newCard = dealer.dealCard();
            if (newCard) {
                currentHand.addCard(newCard);
                cout << currentPlayer.getName() << " drew a card: " << newCard->face() << " of " << newCard->suit() << "\n";
            } else {
                cout << "The deck is empty!\n";
            }
        }

        displayScores(players, matchesDecks, numPlayers);

        // Check end-game conditions
        if (hands[0].isEmpty() || hands[1].isEmpty() || dealer.isDeckEmpty()) {
            gameActive = false;
            cout << "\nGame over! Final Scores:\n";
            displayScores(players, matchesDecks, numPlayers);
            announceWinner(players, matchesDecks, numPlayers);
            break;
        }

        currentPlayerIndex = 1 - currentPlayerIndex; // Switch turns
    }

    // Clean up memory
    for (int i = 0; i < numPlayers; ++i) {
        delete players[i];
    }

    return 0;
}

// Display scores for all players
void displayScores(Player* players[], const Hand matchesDecks[], int numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        cout << players[i]->getName() << "'s Matches Deck: " << matchesDecks[i].getCardCount() / 2 << " sets\n";
    }
}

// Announce the winner
void announceWinner(Player* players[], const Hand matchesDecks[], int numPlayers) {
    int scores[numPlayers];
    for (int i = 0; i < numPlayers; ++i) {
        scores[i] = matchesDecks[i].getCardCount() / 2;
    }

    int maxScore = findMaxScore(scores, numPlayers);
    for (int i = 0; i < numPlayers; ++i) {
        if (scores[i] == maxScore) {
            cout << "\nThe winner is " << players[i]->getName() << " with " << maxScore << " sets!\n";
            return;
        }
    }
    cout << "\nIt's a tie! No clear winner.\n";
}

// Check for initial matches
void checkInitialMatches(Player& player, Hand& hand, Hand& matchesDeck) {
    vector<pair<Card*, Card*> > initialMatches = hand.findMatches();
    for (size_t i = 0; i < initialMatches.size(); ++i) {
        matchesDeck.addCard(initialMatches[i].first);
        matchesDeck.addCard(initialMatches[i].second);
        hand.removeCard(initialMatches[i].first->value());
        hand.removeCard(initialMatches[i].second->value());
    }
    cout << player.getName() << "'s Matches Deck:\n";
    matchesDeck.display();
}

