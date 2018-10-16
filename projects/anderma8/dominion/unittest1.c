/*************************
Matthew Anderson
10/15/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for updateCoins
 *
 * This function sums the value of all treasures in a given player's hand, and sets
 * the game state's 'coins' member to this value.
 */


/********** Helpers **********/

void state_set_hand(struct gameState *state, int *newHand, int handSize) {
    state->handCount[0] = handSize;
    memcpy(state->hand[0], newHand, sizeof(int) * handSize);
    state->coins = 0;
}


void report_result(int expected, int actual) {
    if (expected == actual) {
        puts("\tPassed.");
    } else {
        printf("\tFailed. Expected coin count: %i, but actual was: %i\n", expected, actual);
    }

}

/********************/


int main(int argn, char **argv) {

    struct gameState state;
    int expected;
    int actual;
    int hand[10];

    // Initialize the game state.
    state.coins = 0;

    puts("**********\nUnit Tests for 'updateCoins'\n**********\n");


    /***** Condition: Player has an empty hand *****/
    puts("Player has an empty hand");

    state_set_hand(&state, hand, 0);
    updateCoins(0, &state, 0);

    expected = 0;
    actual = state.coins;
    report_result(expected, actual);


    /***** Condition: Player has no coins in hand. *****/
    puts("\nPlayer has no coins in hand");

    for(int i = 0; i < 5; i++) {
        hand[i] = curse;
    }

    state_set_hand(&state, hand, 5);
    updateCoins(0, &state, 0);

    expected = 0;
    actual = state.coins;
    report_result(expected, actual);


    /***** Condition: Player has coins in hand. *****/
    puts("\nPlayer has coins in hand.");

    for(int i = 0; i < 5; i++) {
        hand[i] = 5;
    }

    state_set_hand(&state, hand, 5);
    updateCoins(0, &state, 0);

    expected = 10;
    actual = state.coins;
    report_result(expected, actual);

    /***** Condition: Bonus is counted. *****/
    puts("\nPlayer has a bonus.");

    updateCoins(0, &state, 1);

    expected = 11;
    actual = state.coins;

    report_result(expected, actual);

    // End of tests.

    puts("\n**********");
    return 0;
}