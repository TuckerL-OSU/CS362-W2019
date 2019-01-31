// Tucker Lavell
// card test 2: smithy
#include "unittests.h"

int smithy_drawCards();
int smithy_discardCard();

int main() {
	int passed = 0;
	int numTests = 2;

	passed += smithy_drawCards();
	passed += smithy_discardCard();

	printf("%d/%d Smithy Card Tests Passed.\n", passed, numTests);
}

int smithy_drawCards() {
	struct gameState* actualGS = newGame();
	struct gameState* expectedGS = newGame();

	int expected = 3;

	gS->whoseTurn = 0;

	// set hand
	gS->handCount[gS->whoseTurn] = 0;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = copper;
	gS->deck[gS->whoseTurn][2] = copper;
	gS->deck[gS->whoseTurn][3] = silver;
	gS->deck[gS->whoseTurn][4] = silver;

	cardEffect(smithy, 0, 0, 0, gS, 0, 0);

	int i;
	if (gS->handCount[gS->whoseTurn] != expected) {
		actual = gS->handCount[gS->whoseTurn];
	}

	return assertTrue(actual, expected);
}

int smithy_discardCard() {
	struct gameState* actualGS = newGame();
	struct gameState* expectedGS = newGame();

	int expected = 3;

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

	int i;
	if (gS->handCount[gS->whoseTurn] != expected) {
		actual = gS->handCount[gS->whoseTurn];
	}

	return assertTrue(actual, expected);
}