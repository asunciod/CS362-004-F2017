//Card test for the village function

#include "dominion.h"
#include <stdio.h>
//Function to check if a test passed or failed
void Pass_Fail(int check)
{
	if(check == 0)
	{
		printf(" Test PASSED succesfuly!\n");
	}
	else
		printf(" TEST FAILED\n");
}

//Function for a unit test for the village card
void Vill()
{
//Random seed
int seed = 500;
struct gameState game;
//Cards used for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game
initializeGame(2, cards, seed, &game);

	printf("\n\nCARD TEST 3 VILLAGE-------------------------------\n\n");
	//Chec the players number of actions and hand count and store them in temps to be used for comparisons later
	printf("\nCheck to see how many actions and cards the player has initially\n");
	printf("\n Player actions:%d\n", game.numActions);
	int temp1 = game.numActions;
	int temp2 = game.handCount[1];
	printf("\n Player cards:%d\n", game.handCount[1]);
	//Run our Village function and make sure it was succseful
	printf("\nCheck to see if the Village function runs succesfully\n");
	int rand = village_func(1, &game, 0);
	Pass_Fail(rand);
	//Get our new hand count and action values
	printf("\nCheck to see how many actions and cards the player has after function call (player cards should not increase/decrease because the Village card will get discarded, number of actions should increase by 2 :\n");
	printf("\n Player actions:%d\n", game.numActions);
	//Compare our old hand count and action values to the new ones and print an error if they are incorrect
	if(game.numActions > temp1 + 2)
	{
	Pass_Fail(1);
	}
	else
	Pass_Fail(0);
	//Compare our old hand count and action values to the new ones and print an error if they are incorrect
	
	printf("\n Player cards:%d\n", game.handCount[1]);
	if(game.handCount[1] < temp2)
	{
	Pass_Fail(1);
	}	
	else
	Pass_Fail(0);
	
	printf("\n\nCARD TEST 3 VILLAGE END------------------------------\n\n");
}

int main()
{
Vill();
return 0;
}
