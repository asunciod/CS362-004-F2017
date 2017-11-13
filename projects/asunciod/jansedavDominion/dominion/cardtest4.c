/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - cardtest4.c
* testing card: outpost
*
* cardtest4: cardtest4.c dominion.o rngs.o
*      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"

int main() {
	
	int loopCount = 5;
	int currentHandCount = 0;
	
	int i;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n\n", TESTCARD);

	// ----------- TEST 1: check outpost played value for player --------------
	printf("TEST 1: check outpost played value for player increments + 1 each time\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//fill hand with outpost cards
	for (i = 0; i < loopCount; i++) {
		testG.hand[0][i] = outpost;
	}
	
	for (i = 0; i < loopCount; i++) {
		//run card effect
		cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
	}
		
	//assertion created to run program and not fail assertion
	printf("loop count = %d, outpostPlayed expected value = %d\n", loopCount, loopCount);

	if (testG.outpostPlayed == loopCount) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}


	// ----------- TEST 2: check handCount, and playedCount when outpost is used --------------
	printf("TEST 2: check hand and discard count when outpost is used \n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//fill hand with outpost cards
	for (i = 0; i < loopCount; i++) {
		testG.hand[0][i] = outpost;
	}
	
	currentHandCount = testG.handCount[0];

	for (i = 0; i < loopCount; i++) {
		//run card effect
		cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);
	}


	printf("current handCount = %d, expected handCount = %d\n", currentHandCount, 0);

	if (testG.handCount[0] == 0) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}

	printf("current playedCardCount = %d, expected playedCardCount = %d\n", 0, loopCount);
		
	if (testG.playedCardCount == loopCount) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}


	printf("\n\n >>>>>Testing complete for %s <<<<<\n\n", TESTCARD);


	return 0;
}


