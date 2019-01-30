// Tucker Lavell
// unit test 2: isGameOver
#include "unittests.h"

int isGameOver_isProvinceEmpty();
int isGameOver_is3SupplyEmpty();
int isGameOver_isGameNOTOver();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += isGameOver_isProvinceEmpty();
	passed += isGameOver_is3SupplyEmpty();
	passed += isGameOver_isGameNOTOver();

	printf("%d/%d isGameOver Tests Passed.\n", passed, numTests);
}

int isGameOver_isProvinceEmpty() {
	struct gameState* gS = newGame();

	gS->supplyCount[province] = 0;

	int expected = 1;
	int actual = isGameOver(gS);


	return assertTrue(actual, expected);

	//free gS;
}

int isGameOver_is3SupplyEmpty() {
	struct gameState* gS = newGame();

	gS->supplyCount[curse] = 0;
	gS->supplyCount[silver] = 0;
	gS->supplyCount[duchy] = 0;

	int expected = 1;
	int actual = isGameOver(gS);


	return assertTrue(actual, expected);

	//free gS;
}

int isGameOver_isGameNOTOver() {
	struct gameState* gS = newGame();
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	initializeGame(2, k, 1, gS);

	int expected = 0;
	int actual = isGameOver(gS);

	// a brand new game shouldn't be ready to end
	return assertTrue(actual, expected);

	//free gS;
}
