/*************************
Matthew Anderson
10/22/2018
CS 362 - Assignment 3
*************************/

#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include "dominion.h"

// Test is given player's hand contains a given card.
int hand_contains(struct gameState *state, int player, int card);

// Counts how many copies of a card are in a given player's hand.
int hand_count_card(struct gameState *state, int player, int card);

// Replaces the given player's hand.
void setHand(struct gameState *state, int player, int newHand[], int size);

// Counts how many copies of a card are in a given player's deck.
int deck_count_card(struct gameState *state, int player, int card);

// Returns 1 if count copies exist in given player's deck. Else, return 0.
int deck_contains_card_exact(struct gameState *state, int player, int card, int count);

#endif