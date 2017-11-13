/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 4 - randomtestadventurer.c
* testing card: adventurer
*
* randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
*      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "card_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {

	int i, j;
	int seed = 1000;
	int numPlayers = 2;
	int temphand[MAX_HAND];
	struct gameState G, testG;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n\n", TESTCARD);

	// ----------- TEST 1: check return value if drawnTreasure parameter is varied --------------
	printf("TEST 1: testing drawnTreasure parameter < 1\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	testG.hand[0][0] = adventurer;

	int min = 2;
	int max = 4;
	int drawntreasure = 0;

	for (i = 0; i < 10; i++) {

		//range of players between 2-4
		numPlayers = (min + (rand() % (int)(max - min + 1)));

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));


		for (j = 0; j < numPlayers; j++) {
			
			//adventurerCard(0, &testG, j, 0, temphand, 0);
			//adventurer_func(&drawntreasure, state, currentPlayer, cardDrawn, temphand, z);
			adventurer_func(&drawntreasure, &testG, j, 0, temphand, 0);

			int countTreasureCards = 0;

			//count how many treasure cards are in hand for randomly selected player
			for (int k = 0; k < 5; k++) {
				int card_val = testG.hand[j][k];
				if (card_val == 4 || card_val == 5 || card_val == 6) {
					countTreasureCards++;
				}
			}
			
			printf("number of treasure cards expected > %d, actual = %d\n", 2, countTreasureCards);
			if (countTreasureCards >= 2) {
				printf("TEST PASS: SUCCESS...\n");
			}
			else {
				printf("TEST PASS: FAILED...\n");
			}
			
			endTurn(&testG);
		}


	}

	printf("\n\n >>>>> Testing complete for %s <<<<<\n\n", TESTCARD);


	return 0;
}


