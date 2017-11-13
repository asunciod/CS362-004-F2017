//Card test for the great hall function
//This can be run multiple time by simply putting a for loop around where my testing is done, I did not do this so it was easier to grade.

#include "dominion.h"
#include <stdio.h>
//Function to check if our tests passed or failed
void Pass_Fail(int check)
{
	if(check == 0)
	{
		printf(" Test PASSED succesfuly!\n");
	}
	else
		printf(" TEST FAILED\n");
}

void Hall()
{
//Generate a random seed
int seed = 500;
struct gameState game;
//Cards needed for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game
initializeGame(2, cards, seed, &game);

	printf("\n\nCARD TEST 3 GREAT HALL-------------------------------\n\n");
	//Get the initial number of actions and cards in the players deck and store them in temps for comparison later
	printf("\nCheck to see how many actions and cards the player has initially\n");
	printf("\n Player actions:%d\n", game.numActions);
	int temp1 = game.numActions;
	int temp2 = game.handCount[1];
	printf("\n Player cards:%d\n", game.handCount[1]);
	//Run the great hall function and make sure it was succesful
	printf("\nCheck to see if the Great Hall function runs succesfully\n");
	int rand = greathall_func(1, &game, 0);
	Pass_Fail(rand);
	//get our new action and card count
	printf("\nCheck to see how many actions and cards the player has after function call (player cards should not increase/decrease because the great hall card will get discarded, number of actions should increase by 1 :\n");
	printf("\n Player actions:%d\n", game.numActions);
	
	//Compare our old hand count and action values to the new ones and print an error if they are incorrect
	if(game.numActions > temp1 + 1)
	{
	Pass_Fail(1);
	}
	else
	Pass_Fail(0);
	//Compare our old hand count and action values to the new ones and print an error if they are incorrect
	
	printf("\n Player cards:%d\n", game.handCount[1]);
	if(game.handCount[1] < temp2 || game.handCount[1] > temp2)
	{
	Pass_Fail(1);
	}	
	else
	Pass_Fail(0);
	
	printf("\n\nCARD TEST 3 GREAT HALL END------------------------------\n\n");
}

int main()
{
Hall();
return 0;
}
