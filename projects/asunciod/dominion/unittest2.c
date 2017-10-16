/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - unittest2.c
* testing function: isGameOver()
*
* testIsGameOver: unittest2.c dominion.o rngs.o
*      gcc -o testIsGameOver -g  unittest2.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int q;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int games_to_play = 4;
	int is_game_over = 0;

	printf("TESTING isGameOver():\n");


	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game

	//there are 24 piles of supply cards
	//game ends in two ways
		//supplyCount[province] == 0 (province = 3)
		//if 3+ supplyCount piles are 0 - supplyCount[i] == 0

	//test 1  - to ensure that the correct int is returned when supplyCount[i] is decremented
		// - check isGameOver before setting supplyCount[random] = 0, expected 0
		// - loop through range < 25 and decrement each supply count
		//		- check isGamveOver before decrement
		//			- expected to be 0, if i < 3
		//			- else 1 if i >= 3
		//		- inner loop is 0 to supplyCount int
		//			- state->supplyCount[i][j]--;//Decrement estates
		//		- check isGamveOver after decrement
		//			- expected to be 0, if i < 2
		//			- else 1 if i >= 2

	//test 2 - to ensure that gameOver only applies if supplyCount[i] <= 2
		// - check isGameOver before setting supplyCount[random] = 0, expected 0
		// - loop through range < 25 and decrement only 2 supply piles
		//		- check isGamveOver before decrement
		//			- expected to be 0
		//		- decrement only if i < 2
		//			- inner loop is 0 to supplyCount int
		//				- state->supplyCount[i][j]--;//Decrement estates
		//		- check isGamveOver after decrement
		//			- expected to be 0

	//test 3 - to ensure that correct int is returned after [province] is set to 0
		// - check isGameOver before setting supplyCount[province] = 0, expected 0
		// - check isGameOver after setting supplyCount[province] = 0, expected 1


	for (q = 0; q < games_to_play; q++) {
		
		//initialize games up to 4 times
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G); // initialize a new game
		
		#if (NOISY_TEST == 1)
			printf("\nSTARTING GAME NUMBER %d........\n", q + 1);
		#endif
		
		// TEST 1
		#if (NOISY_TEST == 1)
				printf("\nCHECKING IS GAME OVER BEFORE TEST 1........\n\n");
		#endif

		//game should not be over since it is the start of a new game
		is_game_over = isGameOver(&G);
		assert(is_game_over == 0);

		for (i = 0; i < 25; i++) {

			is_game_over = isGameOver(&G);
			if (i < 3) {
				assert(is_game_over == 0);
			}
			else {
				assert(is_game_over == 1);
			}

			int supply_count = G.supplyCount[i];

			for (int j = 0; j < supply_count; j++) {
				G.supplyCount[i]--;
			}

			is_game_over = isGameOver(&G);

			if (i < 2) {
				assert(is_game_over == 0);
			}
			else {
				assert(is_game_over == 1);
			}

		}
		#if (NOISY_TEST == 1)
			printf("\nTEST 1 PASSED........\n\n");
		#endif
		//END TEST 1


		//TEST 2 -- make sure that if supply piles <= 3 are 0, then game is not over
		#if (NOISY_TEST == 1)
			printf("\nCHECKING IS GAME OVER BEFORE TEST 2........\n\n");
		#endif

		//refill all supply counts
		for (i = 0; i < 25; i++) {
			G.supplyCount[i] = 10;
		}

		//check before setting 2 supplyCount to 0
		is_game_over = isGameOver(&G);
		assert(is_game_over == 0);

		//select 2 supplyCounts and set to 0
		G.supplyCount[8] = 0;
		G.supplyCount[12] = 0;

		//check after setting 2 supplyCount to 0
		is_game_over = isGameOver(&G);
		assert(is_game_over == 0);

		#if (NOISY_TEST == 1)
			printf("\nTEST 2 PASSED........\n\n");
		#endif
		//END TEST 2
	
		
		//TEST 3 -- check to see if isGameOver returns correct int if supplyCount[province] = 0
		#if (NOISY_TEST == 1)
			printf("\nCHECKING IS GAME OVER BEFORE TEST 3........\n\n");
		#endif
		//refill all supply counts
		for (i = 0; i < 25; i++) {
			G.supplyCount[i] = 10;
		}

		//check before setting supplyCount[province] to 0
		is_game_over = isGameOver(&G);
		assert(is_game_over == 0);

		G.supplyCount[province] = 0;

		//check after setting supplyCount[province] to 0
		is_game_over = isGameOver(&G);
		assert(is_game_over == 1);


		#if (NOISY_TEST == 1)
			printf("\nTEST 3 PASSED........\n\n");
		#endif
		//END TEST 3		
	}

	printf("All tests passed!\n");

	return 0;
}
