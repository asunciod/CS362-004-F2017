/* -----------------------------------------------------------------------
* David Asuncion
* CS 362-400
* Assignment 3 - unittest1.c
* testing function: getCost()
*
* testGetCost: unittest1.c dominion.o rngs.o
*      gcc -o testGetCost -g  unittest1.c dominion.o rngs.o $(CFLAGS)
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
#define NUM_CARDS 27
#define FUNCTION_NAME "getCost()"

int main() {
	int i;
	int seed = 1000;
	int numPlayer = 2;
	int q;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int games_to_play = 4;
	int card_costs[NUM_CARDS] = {
		0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4
	};

	printf("----------------- Testing function: %s ----------------\n\n", FUNCTION_NAME);


	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game

	for (q = 0; q < games_to_play; q++) {
		
		//initialize games up to 4 times
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		initializeGame(numPlayer, k, seed, &G); // initialize a new game
		int current_player = whoseTurn(&G);
		G.handCount[current_player] = 5;

		#if (NOISY_TEST == 1)
			printf("\nSTARTING GAME NUMBER %d........\n", q + 1);
		#endif
		
		// TEST 1 - check all card costs
		#if (NOISY_TEST == 1)
				printf("\nTEST 1 - CHECKING ALL CARD COSTS........\n");
		#endif

		//check all valid card costs
		for (i = -1; i <= NUM_CARDS; i++) {

			if (i < 0 || i > NUM_CARDS - 1) {
				if (getCost(i) == -1) {
					printf("TEST PASS: SUCCESS...\n");
				}
				else {
					printf("TEST PASS: FAILED...\n");
				}
			}
			else {
				if (getCost(i) == card_costs[i]) {
					printf("TEST PASS: SUCCESS...\n");
				}
				else {
					printf("TEST PASS: FAILED...\n");
				}
			}

		}

		#if (NOISY_TEST == 1)
			printf("\nTEST 1 PASSED........\n\n");
		#endif
		//END TEST 1


		//TEST 2 - randomly set cards in hand and check costs
		#if (NOISY_TEST == 1)
			printf("\nTEST 2 - CHECKING CARD COST IN PLAYER'S HAND........\n");
		#endif

		//randomly set hand to a random card
		for (int j = 0; j < 5; j++) {
			int random_num = rand() % 27;
			G.hand[current_player][j] = random_num;
		}
		
		//check all valid card costs
		for (int j = 0; j < 5; j++) {
			int current_card = G.hand[current_player][j];

			for (i = 0; i < NUM_CARDS; i++) {
				
				if (getCost(current_card) == card_costs[current_card]) {
					printf("TEST PASS: SUCCESS...\n");
				}
				else {
					printf("TEST PASS: FAILED...\n");
				}
			}
		}
		
		#if (NOISY_TEST == 1)
				printf("\nTEST 2 PASSED........\n\n");
		#endif
		//END TEST 2
		

		//TEST 3 - set cards in hand to invalid integers and check correct return val
		#if (NOISY_TEST == 1)
				printf("\nTEST 3 - CHECK INVALID CARD COSTS........\n");
		#endif
		
		//set cards in hand to invalid integers
		for (int j = 0; j < 5; j++) {
			int number = j % 2 == 0 ? -1 : 45;
			G.hand[current_player][j] = number;
		}

		//check all valid card costs
		for (int j = 0; j < 5; j++) {
			int current_card = G.hand[current_player][j];
			
			if (getCost(current_card) == -1) {
				printf("TEST PASS: SUCCESS...\n");
			}
			else {
				printf("TEST PASS: FAILED...\n");
			}
		}

		#if (NOISY_TEST == 1)
				printf("\nTEST 3 PASSED........\n\n");
		#endif
		//END TEST 3
	}

	printf("\n\n >>>>> Testing complete for %s <<<<<\n\n", FUNCTION_NAME);

	return 0;
}