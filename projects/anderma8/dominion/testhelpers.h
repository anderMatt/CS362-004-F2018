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
void game_state_set_hand_random(struct gameState *state, int player, int handSize);

/*
Initializes a game with randomized state.
*/
void game_state_initialize_random(struct gameState *state);

/*
Checks that expected == actual. If false, reports an error.
*/

void report_result(int expected, int actual, char *errMsg);

/*
Checks if the game states pointed to by pre and post are equal. If
not, prints the error message and returns 0. Else, returns 1.
*/
int game_state_is_equal(struct gameState *pre, struct gameState *post, char *errMsg);
#endif