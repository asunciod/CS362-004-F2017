#ifndef _CARD_HELPERS_H
#define _CARD_HELPERS_H

int smithyCard(int i, int currentPlayer, struct gameState *state, int handPos);
int adventurerCard(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int temphand[], int z);
int gardensCard();
int outpostCard(struct gameState *state, int handPos, int currentPlayer);
int feastCard(int i, struct gameState *state, int currentPlayer, int temphand[], int x, int choice1);

#endif
