/**************************************************
 * Matthew Anderson
 * 10/31/18
 * CS 362 Assignment 4
 * 
 * Helper functions for assignment 4.
**************************************************/
#include <string.h>
#include <math.h>

#include "rngs.h"
#include "dominion.h"

/*
Returns a random Dominion card, selected from the pool
of all cards.
*/
int get_random_dominion_card() {
    return floor(Random() * treasure_map);
}

/*
Sets the given players hand to a random selection of cards.
*/
void game_state_set_hand(struct gameState *state, int player, int handSize) {
    int newHand[handSize];

    // Generate the random hand.
    int i,
        card;

    for(i = 0; i < handSize; i++) {
        card = get_random_dominion_card();
        state->hand[player][i] = card;
    }

    // Update hand count to reflect the new hand.
    state->handCount[player] = handSize;
}
