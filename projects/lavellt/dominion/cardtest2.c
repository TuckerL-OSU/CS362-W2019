// Tucker Lavell
// card test 2: smithy
#include "unittests.h"

int smithy_numCardsDrawn();
int smithy_numCardsDiscarded();

int main() {
	int passed = 0;
	int numTests = 2;

	passed += smithy_numCardsDrawn();
	passed += smithy_numCardsDiscarded();

	printf("%d/%d Smithy Card Tests Passed.\n", passed, numTests);
}

// check number of cards smithy causes us to draw
int smithy_numCardsDrawn() {
	struct gameState* gS = newGame();

	int expected = 3;
	int actual = 0;

	gS->whoseTurn = 0;

	// set hand
	gS->handCount[gS->whoseTurn] = 1;
	gS->hand[gS->whoseTurn][0] = smithy;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = copper;
	gS->deck[gS->whoseTurn][2] = copper;
	gS->deck[gS->whoseTurn][3] = silver;
	gS->deck[gS->whoseTurn][4] = silver;

	cardEffect(smithy, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->handCount[gS->whoseTurn];
	}

	printf("1. Number of Cards Drawn: ");
	return assertTrue(actual, expected);
}

// check to make sure smithy was discarded afterwards
int smithy_numCardsDiscarded() {
	struct gameState* gS = newGame();

	int expected = 3;
	int actual = 0;

	gS->whoseTurn = 0;

	// set hand
	gS->handCount[gS->whoseTurn] = 1;
	gS->hand[gS->whoseTurn][0] = smithy;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = copper;
	gS->deck[gS->whoseTurn][2] = copper;
	gS->deck[gS->whoseTurn][3] = silver;
	gS->deck[gS->whoseTurn][4] = silver;

	cardEffect(smithy, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->handCount[gS->whoseTurn];
	}

	printf("2. Number of Cards Discarded: ");
	return assertTrue(actual, expected);
}
