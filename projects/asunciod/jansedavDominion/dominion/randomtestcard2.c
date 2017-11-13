//Random test for the GREAT HALL card function

#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Function for a unit test for the GREAT HALL card
void Hall()
{
//Random seed
int i;
int actionsucc = 0;
int actionfail = 0;
int handsucc = 0;
int handfail = 0;
int gamesucc = 0;
int gamefail = 0;

struct gameState game;
//Cards used for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};
//Initialize the game


	printf("\n\nRANDOM TESTING FOR GREATHALL CARD START 300 RUNS-------------------------------\n\n");

//Tests run for 400 runs
	for(i = 0; i < 400; i++)
	{

	//Randomly selected player
	int rand1 = rand() % 4;
	printf("\nRun #: %d\n", i+1);
	printf("Currently testing player: %d\n", rand1);

	//Randomly selected seed
	int rand2 = rand() % 2000;
	//Random actions and hand count
	int temp1 = rand() % 30;
	int temp2 = rand() % 30;

	printf("Number of Actions BEFORE card is played: %d\n", temp1);
	printf("Number of cards BEFORE card is played: %d\n", temp2);

	initializeGame(rand1, cards, rand2, &game);
		
		//Here I am setting a random initial amount of actions and hand count for the randomly selected player that we are currently testing.
		game.numActions = temp1;
		game.handCount[rand1] = temp2;
		//Run our Village function and make sure it was succseful
		int temp3 = greathall_func(rand1, &game, 0);

		printf("Number of Actions AFTER card is played: %d\n", game.numActions);
		printf("Number of cards AFTER card is played: %d\n", game.handCount[rand1]);
	
		//make the first ten runs fail on purpose so I can see if my tests are working correctly.
		if(i <= 10)
		{
		temp1 = -1;
		temp2 = -1;
		temp3 = -1;
		}

		//keep track of how many times the card was succesfully played and not played
		if(temp3 == 0)
		{
			gamesucc++;
		}
		else
		{
			printf("\nCARD PLAY FAILED");
			gamefail++;
		}

		//Compare our old hand count and action values to the new ones and keep track of the success and failures
		if(game.numActions > temp1 + 1)
		{
			actionfail++;
			printf("\nACTIONCOUNT FAILED\n");
		}
		else
		{
			actionsucc++;
		}
		//Compare our old hand count and action values to the new ones and keep track of the success and failures
	
		if(game.handCount[rand1] != temp2)
		{
			handfail++;
			printf("\nHANDCOUNT FAILED\n");
		}	
		else
		{
		handsucc++;
		}
	}
	//Print out the number of successes and fails of each test.
	printf("\n\nTOTALS:\n");
	printf("Number of SUCCESFUL Great Hall card function runs: %d\n", gamesucc);
	printf("Number of FAILED Great Hall card function runs: %d\n", gamefail);
	printf("Number of SUCCESFUL action values: %d\n", actionsucc);
	printf("Number of FAILED action values: %d\n", actionfail);
	printf("Numebr of SUCCESFUL hand values: %d\n", handsucc);
	printf("Number of FAILED hand values: %d\n", handfail);
	printf("\n\nEND OF RANDOM TESTS FOR GREAT HALL CARD------------------------------\n\n");
}

int main()
{
Hall();
return 0;
}
