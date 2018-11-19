/*************************
Matthew Anderson
10/15/2018
CS 362 - Assignment 3
*************************/

#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "testhelpers.h"

/*
 * Unit tests for isGameOver
 *
 * This function checks if the game is over given
 * the current game state.
 *
 */


int main(int argn, char **argv) {
    struct gameState state;
    int gameOver;

    puts("**********\nUnit Tests for 'isGameOver'\n**********\n");


    /***** Condition: Game is over due to no provinces remaining. *****/
    puts("No provinces remaining: game over");

    state.supplyCount[province] = 0;
    gameOver = isGameOver(&state);
    report_result(1, gameOver, "Expected game to be over.");

    /***** Condition: Game is over due to three empty supply lines. *****/
    puts("Three supply lines depleted: game over.");

    replenish_supply_count(&state);

    state.supplyCount[0] = 0;
    state.supplyCount[5] = 0;
    state.supplyCount[24] = 0;

    gameOver = isGameOver(&state);
    report_result(1, gameOver, "Expected game to be over.");


    /***** Condition: No empty supply lines. *****/
    puts("No empty supply lines. Provinces still remaining: game not over.");

    replenish_supply_count(&state);
    state.supplyCount[province] = 5;

    gameOver = isGameOver(&state);
    report_result(0, gameOver, "Game should not be over.");



    /***** Condition: Less than three empty supply lines *****/
    puts("Two supply lines depleted: game not over.");

    replenish_supply_count(&state);
    state.supplyCount[province] = 1;
    state.supplyCount[0] = 0;
    state.supplyCount[24] = 0;

    gameOver = isGameOver(&state);
    report_result(0, gameOver, "Game should not be over.");

    return 0;

}