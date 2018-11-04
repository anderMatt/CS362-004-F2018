/**************************************************
 * Matthew Anderson
 * 10/31/18
 * CS 362 Assignment 4
 * 
 * Helper functions for assignment 4.
**************************************************/

#include <stdio.h>
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
void game_state_set_hand_random(struct gameState *state, int player, int handSize) {

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

/*
Initializes a game with randomized state.
*/
void game_state_initialize_random(struct gameState *state) {
    int numPlayers = floor(Random() * MAX_PLAYERS);
    int kingdomCards[10];

    int i;
    for(i = 0; i < 10; i++) {
        kingdomCards[i] = get_random_dominion_card();
    }

    initializeGame(numPlayers, kingdomCards, 1, state);
    int deckSize = sizeof(state->deckCount[0]) / sizeof(int);
    state->deckCount[0] = deckSize;

}

void report_result(int expected, int actual, char *errMsg) {
    if (expected == actual) {
        printf("\t\tPassed.\n");
    } else {
        printf(errMsg, expected, actual);
    }
}

int game_state_is_equal(struct gameState *pre, struct gameState *post, char *errMsg) {
    if(memcmp(pre, post, sizeof(struct gameState)) != 0) {
        puts(errMsg);
        return 0;  // Not equal.
    }

    return 1;
}