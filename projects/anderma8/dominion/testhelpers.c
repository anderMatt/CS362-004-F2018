/*************************
Matthew Anderson
10/22/2018
CS 362 - Assignment 3
*************************/

#include "dominion.h"
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