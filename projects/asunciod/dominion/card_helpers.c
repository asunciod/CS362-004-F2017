#include "card_helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int smithyCard(int i, int currentPlayer, struct gameState *state, int handPos) {
	//+3 Cards
	for (i = 0; i < 3; i++)
	{
		drawCard(currentPlayer, state);
	}

	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z) {
	while (drawntreasure < 2) {

		//if the deck is empty we need to shuffle discard and add to deck
		// [BUG] removed conditional to check amount of card in a deck for the current player
		// [BUG RESULT] Adventurer card will always shuffle the player's deck regardless of amount
		shuffle(currentPlayer, state);

		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
	return 0;
}

int gardensCard() {
	return -1;
}

int outpostCard(struct gameState *state, int handPos, int currentPlayer) {
	//set outpost flag
	// [BUG] outpostPlayed flag is set to 0 instead of incrementing + 1
	// [BUG RESULT] Since outpostPlayed flag is never set to 1, the effect of the outpost card is never met
	state->outpostPlayed = 0;

	//discard card
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}

int feastCard(int i, struct gameState *state, int currentPlayer, int temphand[], int x, int choice1) {
	//gain card with cost up to 5
	//Backup hand
	for (i = 0; i <= state->handCount[currentPlayer]; i++) {
		temphand[i] = state->hand[currentPlayer][i];//Backup card
		state->hand[currentPlayer][i] = -1;//Set to nothing
	}
	//Backup hand

	//Update Coins for Buy
	// [BUG] increased coins for buy from 5 to 50
	// [BUG RESULT] Feast card allows player to gain a card up to 50 coins instead of 5
	updateCoins(currentPlayer, state, 50);
	x = 1;//Condition to loop on
	while (x == 1) {//Buy one card
		if (supplyCount(choice1, state) <= 0) {
			if (DEBUG)
				printf("None of that card left, sorry!\n");

			if (DEBUG) {
				printf("Cards Left: %d\n", supplyCount(choice1, state));
			}
		}
		else if (state->coins < getCost(choice1)) {
			printf("That card is too expensive!\n");

			if (DEBUG) {
				printf("Coins: %d < %d\n", state->coins, getCost(choice1));
			}
		}
		else {

			if (DEBUG) {
				printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
			}

			gainCard(choice1, state, 0, currentPlayer);//Gain the card
			x = 0;//No more buying cards

			if (DEBUG) {
				printf("Deck Count: %d\n", state->handCount[currentPlayer] + state->deckCount[currentPlayer] + state->discardCount[currentPlayer]);
			}

		}
	}

	//Reset Hand
	for (i = 0; i <= state->handCount[currentPlayer]; i++) {
		state->hand[currentPlayer][i] = temphand[i];
		temphand[i] = -1;
	}
	//Reset Hand

	return 0;
}
