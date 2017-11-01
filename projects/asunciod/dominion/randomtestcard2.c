/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 4 - randomtestcard2.c
* testing function: whoseTurn()
*
* randomtestcard2: randomtestcard2.c dominion.o rngs.o
*      gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define FUNCTION_NAME "whoseTurn()"

int main() {
	int seed = 1000;
	int numPlayer;
	int gamesLength = 5;
	int p, q;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;

	printf("----------------- Testing function: %s ----------------\n\n", FUNCTION_NAME);

	for (q = 0; q < gamesLength; q++) {

		//initialize games up to 4 times
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		
		numPlayer = rand() % 2 + 4;	//randomly select number of players
		int initVal = initializeGame(numPlayer, k, seed, &G); // initialize a new game

		//make sure gamestate is valid
		if (initVal != -1) {

			//loop to check player turns
			for (p = 0; p < 10; p++) {

				//get current player
				int current_player = whoseTurn(&G);

				printf("number of players range = 0 to 3; current player, %d, expected to be within range, else fail\n", current_player);


				if (current_player >= 0 && current_player <= numPlayer) {
					printf("TEST PASS: SUCCESS...\n");
				}

				endTurn(&G);
			}

		}
		
	}

	printf("\n\n >>>>> Testing complete for %s <<<<<\n\n", FUNCTION_NAME);

	return 0;
}
