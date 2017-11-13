// Card test for adventurer

#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void adventur()
{
struct gameState game;
//Cards needed for initialization
int cards[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map};

//These hold the successes and failures of each variable test
int treasuresucc = 0;
int treasurefail = 0;
int handsucc = 0;
int handfail = 0;
int cardfail = 0;
int cardsucc = 0;
int i;

printf("\n\nRANDOM TESTING FOR ADVENTURER CARD START--------------------------------------------------------------\n\n");

//Run it 200 times
for(i = 0; i < 200; i++)
{
printf("\nRun #: %d\n", i);
//Random treasure amount
int temp1 = rand() % 20;
//Random handcount amount
int temp2 = rand() % 20;
//create a random hand
int temp4 = rand() % 30;
int temp3;
//Random player
int rand1 = rand() % 4;


printf("Currently testing player: %d\n", rand1);
//Random seed number
int rand2 = rand() % 1000;
//Print off the starting hand counts and treasure for comparison
printf("Hand count BEFORE card is played: %d\n", temp2);

printf("Treasure BEFORE card is played: %d\n", temp1);
//Temporary hand that is created randomly
int temphand[temp4];
//Set treasure to its random number
int treasure = temp1;

//Initialize the game.
initializeGame(rand1, cards, rand2, &game);
//Set hand count to its random number
game.handCount[rand1] = temp2;
//Run the adventurer function to see if it was successful
temp3 = adventurer_func(&treasure, &game, rand1, 0, temphand, 0);

//Find the counts of handcount and treasure after it was ran.
printf("Hand count AFTER card is played: %d\n", game.handCount[rand1]);
printf("Treasure count AFTER card is played: %d\n", treasure);

//I purposely fail tests here to make sure that my tests will work is something is incorrect or correct.
if(i < 10)
{
temp1 = treasure;
temp2 = -1;
temp3 = -1;
}

	//Keep track of succesful amoounts of treasure and wrong amounts.
	if(treasure > temp1+1)
	{
	printf("\nFAILED TREASURE COUNT\n");
	treasurefail++;
	}
	else
	{
	treasuresucc++;
	}
	//Keep track of the number of successful and failed hand counts
	if(game.handCount[rand1] != temp2+1)
	{
	printf("\nFAILED HANDCOUT\n");
	handfail++;
	}
	else
	{
	handsucc++;
	}
	//Keep track of the number of successful card plays and failures
	if(temp3 == 0)
	{
	cardsucc++;
	}
	else
	{
	printf("\nFAILED CARD\n");
	cardfail++;
	}
}

//Printing the totals for the 200 runs.
printf("\n\n TOTALS:\n");
printf("Number of SUCCESFUL adventure card runs: %d\n", cardsucc);
printf("Number of FAILED adventure card runs: %d\n", cardfail);
printf("Number of SUCCESFUL handcounts: %d\n", handsucc);
printf("Number of FAILED handcounts: %d\n", handfail);
printf("Number of SUCCESFUL treasure counts: %d\n", treasurefail);
printf("Number of FAILED treasure counts: %d\n", treasuresucc);
printf("\n\nRANDOM TESTING FOR ADVENTURER CARD END---------------------------------------------------------------\n");
}

int main()
{
adventur();
return 0;
}
