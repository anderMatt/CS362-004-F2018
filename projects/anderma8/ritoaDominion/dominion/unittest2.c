/*************************
Matthew Anderson
11/21/2018
CS 362 - Assignment 5
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "testhelpers.h"

/*
 * Unit tests for numHandCards
 *
 * This function returns the number of card's in the current
 * turn player's hand.
 */


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
    char errMsg[100];
    snprintf(errMsg, 100, "Expected hand count: %i, but actual hand count was: %i", expected, actual);

    report_result(expected, actual, errMsg);

    /***** Condition: Max cards in hand *****/
    puts("Player has maximum number of cards in hand.");
    state.handCount[turnPlayer] = MAX_HAND;

    expected = MAX_HAND;
    actual = numHandCards(&state);
    snprintf(errMsg, 100, "Expected hand count: %i, but actual hand count was: %i", expected, actual);

    report_result(expected, actual, errMsg);

    return 0;

}