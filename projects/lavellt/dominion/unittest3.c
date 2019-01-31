// Tucker Lavell
// unit test 3: updateCoins
#include "unittests.h"

int updateCoins_coinReset_add1Copper();
int updateCoins_add10Gold();
int updateCoins_add1ofEach();
int updateCoins_addBonus();

int main() {
	int passed = 0;
	int numTests = 4;

	passed += updateCoins_coinReset_add1Copper();
	passed += updateCoins_add10Gold();
	passed += updateCoins_add1ofEach();
	passed += updateCoins_addBonus();

	printf("%d/%d updateCoins Tests Passed.\n", passed, numTests);
}

int updateCoins_coinReset_add1Copper() {
	struct gameState* gS = newGame();

	// with -1 we can get 0 if reset does not work but add does,
	// or we can get 1 if reset works and add works,
	// and -1 would prove that update doesn't work
	gS->whoseTurn = 0;
	gS->coins = -1;

	// need to set proper number hanlers


	//drawCard(gS->whoseTurn, gS);
	// overwrite the card to guarntee it is a copper
	gS->hand[gS->whoseTurn][0] = copper;
	gS->handCount[gS->whoseTurn] = 1;

	updateCoins(gS->whoseTurn, gS, 0);
	
	int expected = 1;
	int actual = gS->coins; // check coins after update

	return assertTrue(actual, expected);

	//free gS;
}

// if this add works, it would be reasonable to assume 
// multiple bronze and silver will work
int updateCoins_add10Gold() {
	struct gameState* gS = newGame();
	gS->whoseTurn = 0;

	int i;
	// set P1s hand to only 10 golds
	for (i = 0; i < 10; i++) {
		gS->hand[gS->whoseTurn][i] == gold;
	}
	gS->handCount[gS->whoseTurn] = 10;

	updateCoins(gS->whoseTurn, gS, 0);

	int expected = 60;
	int actual = gS->coins; // check coins after update

	return assertTrue(actual, expected);

	//free gS;
}

int updateCoins_add1ofEach() {
	struct gameState* gS = newGame();
	gS->whoseTurn = 0;

	gS->hand[0][0] == copper;
	gS->hand[0][1] == silver;
	gS->hand[0][2] == gold;

	gS->handCount[gS->whoseTurn] = 3;

	updateCoins(gS->whoseTurn, gS, 0);

	int expected = 6;
	int actual = gS->coins; // check coins after update

	return assertTrue(actual, expected);

	//free gS;
}

int updateCoins_addBonus() {
	struct gameState* gS = newGame();

	gS->hand[0][0] == curse;

	// try 1 bonus coin
	updateCoins(0, gS, 1);

	int expected = 1;
	int actual = gS->coins; // check coins after update

	return assertTrue(actual, expected);

	//free gS;
}
