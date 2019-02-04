// Tucker Lavell
// card test 2: smithy
#include "unittests.h"

int smithy_numCardsDrawn();
int smithy_numCardsInHand();
int smithy_smithyDiscarded();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += smithy_numCardsDrawn();
	passed += smithy_numCardsInHand();
	passed += smithy_smithyDiscarded();

	printf("%d/%d Smithy Card Tests Passed.\n", passed, numTests);
}

// check number of cards smithy causes us to draw
int smithy_numCardsDrawn() {
	struct gameState* gS = newGame();

	int expected = 2;
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
		actual = gS->deckCount[gS->whoseTurn];
	}

	printf("1. Check Number of Cards in Deck: ");
	return assertTrue(actual, expected);
}

// check to make sure smithy was discarded afterwards
int smithy_numCardsInHand() {
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

	printf("2. Check Number of Cards in hand: ");
	return assertTrue(actual, expected);
}

int smithy_smithyDiscarded() {
	struct gameState* gS = newGame();

	int expected = smithy;
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

	gS->playedCardCount = 0;

	cardEffect(smithy, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->playedCards[gS->playedCardCount];
	}

	printf("3. Check Discard for Smithy: ");
	return assertTrue(actual, expected);
}