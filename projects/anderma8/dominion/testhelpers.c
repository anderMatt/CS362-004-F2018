/**************************************************
 * Matthew Anderson
 * 11/12/18
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

/*
Inititalizes game state with pre-determined state variables. Initializes
more state variables than game_state_initialize_random.

Code adapted from class lectures.
*/
void game_state_initialize_random_full(struct gameState *state) {
    // Clear existing state.
    memset(state, 0, sizeof(struct gameState));
    int kingdomCards[10];
    for(int i = 0; i < 10; i++) {
        kingdomCards[i] = get_random_dominion_card();  // No teasures or victory cards - we'll add these on test-by-test basis.
    }
    initializeGame(2, kingdomCards, 100, state);

    // Player deck
    int playerDeck[10];
    for (int j = 0; j < 10; j++) {
        playerDeck[j] = council_room + j;
    }

    // Player discard pile
    int playerDiscard[5];
    for (int k = 0; k < 5; k++) {
        playerDiscard[k] = great_hall + k;
    }


    // Now, set the game state variables.
    state->handCount[0] = 10;
    state->deckCount[0] = 10;
    state->discardCount[0] = 5;
    memcpy(state->hand[0], kingdomCards, sizeof(int) * state->handCount[0]);
    memcpy(state->deck[0], playerDeck, sizeof(int) * state->deckCount[0]);
    memcpy(state->discard[0], playerDiscard, sizeof(int) * 5);

    // Now, set the second player's state variables
    state->handCount[1] = 10;
    state->deckCount[1] = 10;
    state->discardCount[1] = 5;
    memcpy(state->hand[1], kingdomCards, sizeof(int) * state->handCount[1]);
    memcpy(state->deck[1], playerDeck, sizeof(int) * state->deckCount[1]);
    memcpy(state->discard[1], playerDiscard, sizeof(int) * 5);

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