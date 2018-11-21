/**************************************************
 * Matthew Anderson
 * 11/21/18
 * CS 362 Assignment 5
 * 
 * Helper functions for assignment 5.
**************************************************/

#ifndef _TEST_HELPERS_H
#define _TEST_HELPERS_H

#include "dominion.h"

/*
Sets the given players hand to a random selection of cards.
*/
void game_state_set_hand_random(struct gameState *state, int player, int handSize);

/*
Initializes a game with randomized state.
*/
void game_state_initialize_random(struct gameState *state);

/*
Initializes a game with randomized state. Initializes more
state variables than game_state_initialize_random.
*/
void game_state_initialize_random_full(struct gameState *state);

/*
Checks that expected == actual. If false, reports an error.
*/

void report_result(int expected, int actual, char *errMsg);

/*
Checks if the game states pointed to by pre and post are equal. If
not, prints the error message and returns 0. Else, returns 1.
*/
int game_state_is_equal(struct gameState *pre, struct gameState *post, char *errMsg);




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

void report_result(int expected, int actual, char *errMsg);

// Refills all supply counts.
void replenish_supply_count(struct gameState *state);

#endif