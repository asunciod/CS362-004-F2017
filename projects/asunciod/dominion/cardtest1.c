/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - cardtest1.c
* testing card: smithy
*
* cardtest1: cardtest1.c dominion.o rngs.o
*      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"
//test 1
//	 check position of smithy card in hand
//
//	after test
//		 check position of where smithy card was
//		 this checks that smithy card was discarded
//
//test 2
//	 check amount of cards in hand -- this assertion should fail
//		 smithy card should give +3, but BUG introduced only gives 1 
//		 expected is current hand + 2 (+3 action -1 discard), but will be +0 (+1 action -1 discard)

int main() {

	int newCards = 0;
	int discarded = 1;
		
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int seed = 1000;
	int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n\n", TESTCARD);

	// ----------- TEST 1: smithy card played --------------
	printf("TEST 1: check hand and played cards for smithy card\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[0][0] = smithy;
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("hand position %d = smithy card (13), expected = any card not smithy (13)\n", handpos);
	if (testG.hand[0][0] != smithy) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}


	int playedCards = testG.playedCards[0];			
	int playedCardCount = testG.playedCardCount;	

	printf("played cards = null, expected = 13\n");
	if (playedCards == smithy) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}


	printf("played cards count = 0, expected = 1\n");

	if (playedCardCount == 1) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}

	// ----------- TEST 2: check smithy card action; +3 draw --------------
	printf("TEST 2: check hand and played cards for smithy card\n");
	
	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[0][0] = smithy;

	newCards = 3;
	int handcount_before = testG.handCount[0];
	int handcount_expected = handcount_before + newCards - discarded;
	
	cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

	printf("current hand count = %d, expected = %d\n", handcount_before, handcount_expected);

	if (testG.handCount[0] == handcount_expected) {
		printf("TEST PASS: SUCCESS...\n");
	}
	else {
		printf("TEST PASS: FAILED...\n");
	}

	printf("\n\n >>>>> Testing complete for %s <<<<<\n\n", TESTCARD);


	return 0;
}


