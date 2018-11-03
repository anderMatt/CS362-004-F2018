/**************************************************
 * Matthew Anderson
 * 10/31/18
 * CS 362 Assignment 4
 * 
 * Helper functions for assignment 4.
**************************************************/

#ifndef _TEST_HELPERS_H
#define _TEST_HELPERS_H

/*
Sets the given players hand to a random selection of cards.
*/
void game_state_set_hand(struct gameState *state, int player, int handSize);

/*
Initializes a game with randomized state.
*/
void game_state_initialize_random(struct gameState *state);

/*
Checks that expected == actual. If false, reports an error.
*/

void report_result(int expected, int actual, char *errMsg);

#endif