#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
	int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);
void adventurerCardEffect(int currentPlayer, int drawntreasure, int cardDrawn, int z, struct gameState *state);
void smithyCardEffect(int currentPlayer, int handPos, struct gameState *state);
void villageCardEffect(int currentPlayer, int handPos, struct gameState *state);
void greatHallCardEffect(int currentPlayer, int handPos, struct gameState *state);
void outpostCardEffect(int currentPlayer, int handPos, struct gameState *state);
int cardEffect(int card, int choice1, int choice2, int choice3,
	struct gameState *state, int handPos, int *bonus);

#endif