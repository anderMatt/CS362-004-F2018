/**************************************************
 * Matthew Anderson
 * 11/21/18
 * CS 362 Assignment 5
 * 
 * Helper functions for assignment 5.
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
        playerDeck[j] = get_random_dominion_card();
    }

    // Player discard pile
    int playerDiscard[5];
    for (int k = 0; k < 5; k++) {
        playerDiscard[k] = get_random_dominion_card();
    }


    // Now, set the game state variables.
    state->handCount[0] = 10;
    state->deckCount[0] = 10;
    state->discardCount[0] = 5;
    memcpy(state->hand[0], kingdomCards, sizeof(int) * floor(Random() * MAX_HAND));
    memcpy(state->deck[0], playerDeck, sizeof(int) * state->deckCount[0]);
    memcpy(state->discard[0], playerDiscard, sizeof(int) * floor(Random() * MAX_HAND));

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


#include "testhelpers.h"
#include "string.h"

int hand_contains(struct gameState *state, int player, int card) {
    for (int i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) {
            return 1;
        }
    }

    return 0;
}

void setHand(struct gameState *state, int player, int newHand[], int size) {
    memcpy(state->hand[player], newHand, sizeof(int) * size);
    state->handCount[player] = size;
}

int hand_count_card(struct gameState *state, int player, int card) {
    int counter = 0;
    for (int i = 0; i < state->handCount[player]; i++) {
        if (state->hand[player][i] == card) {
            counter++;
        }
    }

    return counter;
}

int deck_count_card(struct gameState *state, int player, int card) {
    int counter = 0;
    for (int i = 0; i < state->deckCount[player]; i++) {
        if (state->deck[player][i] == card) {
            counter++;
        }
    }

    return counter;
}

int deck_contains_card_exact(struct gameState *state, int player, int card, int count) {
    int counter = 0;
    for (int i = 0; i < state->deckCount[player]; i++) {
        if (state->deck[player][i] == card) {
            counter++;
        }
    }

    return (counter == count);
}

void replenish_supply_count(struct gameState *state) {
    for (int i = 0; i < 25; i++) {
        state->supplyCount[i] = 10;
    }
}


// void report_result(int expected, int actual, char *errMessage) {
//     if (expected == actual) {
//         puts("\t\tPassed.");
//     } else {
//         printf("\t\tFailed. %s\n", errMessage);
//     }
// }