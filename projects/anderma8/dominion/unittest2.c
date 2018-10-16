/*************************
Matthew Anderson
10/15/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"

/*
 * Unit tests for numHandCards
 *
 * This function returns the number of card's in the current
 * turn player's hand.
 */



void report_result(int expected, int actual) {
    if (expected == actual) {
        puts("\tPassed.");
    } else {
        printf("\tFailed. Expected hand count: %i, but actual was: %i\n", expected, actual);
    }

}


int main(int argn, char **argv) {
    struct gameState state;
    int expected;
    int actual;

    /* Initialize state. */
    int turnPlayer = 0;
    state.whoseTurn = turnPlayer;

    puts("**********\nUnit Tests for 'numHandCards'\n**********\n");


    /***** Condition: No cards in hand *****/
    puts("Player has no cards in hand.");
    state.handCount[turnPlayer] = 0;

    expected = 0;
    actual = numHandCards(&state);

    report_result(expected, actual);

    /***** Condition: Max cards in hand *****/
    puts("Player has maximum number of cards in hand.");
    state.handCount[turnPlayer] = MAX_HAND;

    expected = MAX_HAND;
    actual = numHandCards(&state);

    report_result(expected, actual);

}