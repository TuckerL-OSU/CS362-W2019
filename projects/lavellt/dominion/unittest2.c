// Tucker Lavell
// unit tests 2: isGameOver
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isGameOver_isProvinceEmpty();
int isGameOver_is3SupplyEmpty();
int isGameOver_isGameNOTOver();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += isGameOver_isProvinceEmpty();
	passed += isGameOver_is3SupplyEmpty();
	passed += isGameOver_isGameNOTOver();

	printf("%d/%d isGameOver Tests Passed.", passed, numTests);
}

int isGameOver_isProvinceEmpty() {
	struct gameState* gS = newGame();

	gS->supplyCount[province] = 0;

	int expected = 1;
	int actual = isGameOver(gS);


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	//free gS;
}

int isGameOver_is3SupplyEmpty() {
	struct gameState* gS = newGame();
	//int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
	//	sea_hag, tribute, smithy };
	//initializeGame(2, k, 1, &gS);

	gS->supplyCount[curse] = 0;
	gS->supplyCount[silver] = 0;
	gS->supplyCount[duchy] = 0;

	int expected = 1;
	int actual = isGameOver(gS);


	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	//free gS;
}

int isGameOver_isGameNOTOver() {
	struct gameState* gS = newGame();
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	initializeGame(2, k, 1, &gS);

	int expected = 0;
	int actual = isGameOver(gS);

	// a brand new game shouldn't be ready to end
	if (actual == expected) {
		printf("TEST  SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}

	//free gS;
}
