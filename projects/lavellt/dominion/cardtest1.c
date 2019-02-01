// Tucker Lavell
// card test 1: adventurer
#include "unittests.h"

int adventurer_treasuresDrawn();
int adventurer_discardCards();
int adventurer_cardsLeftInDeck();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += adventurer_treasuresDrawn();
	passed += adventurer_discardCards();
	passed += adventurer_cardsLeftInDeck();

	printf("%d/%d Adventurer Card Tests Passed.\n", passed, numTests);
}

// check to see if the cards we kept were treasures
int adventurer_treasuresDrawn() {
	struct gameState* gS = newGame();
	int expected = 2;
	int actual = 0;

	gS->whoseTurn = 0;
	// set hand
	gS->hand[gS->whoseTurn][0] = feast;
	gS->handCount[gS->whoseTurn] = 1;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = baron;
	gS->deck[gS->whoseTurn][2] = silver;
	gS->deck[gS->whoseTurn][3] = baron;
	gS->deck[gS->whoseTurn][4] = gold;

	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);

	int i;
	for (i = 0; i < gS->handCount[gS->whoseTurn]; i++) {
		if (gS->hand[gS->whoseTurn][i] == copper ||
			gS->hand[gS->whoseTurn][i] == silver ||
			gS->hand[gS->whoseTurn][i] == gold) {
			actual++;
		}
	}

	return assertTrue(actual, expected);
}

// check to see how many cards were discarded based off the loaded deck
int adventurer_discardCards() {
	struct gameState* gS = newGame();
	int expected = 1;
	int actual = 0;

	gS->whoseTurn = 0;
	// set hand
	gS->hand[gS->whoseTurn][0] = feast;
	gS->handCount[gS->whoseTurn] = 1;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = baron;
	gS->deck[gS->whoseTurn][2] = silver;
	gS->deck[gS->whoseTurn][3] = baron;
	gS->deck[gS->whoseTurn][4] = gold;

	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->discardCount[gS->whoseTurn];
	}

	return assertTrue(actual, expected);
}

// check how many cards are left in the loaded deck
int adventurer_cardsLeftInDeck() {
	struct gameState* gS = newGame();
	int expected = 2;
	int actual = 0;

	gS->whoseTurn = 0;
	// set hand
	gS->hand[gS->whoseTurn][0] = feast;
	gS->handCount[gS->whoseTurn] = 1;
	// "load" deck
	gS->deckCount[gS->whoseTurn] = 5;
	gS->deck[gS->whoseTurn][0] = copper;
	gS->deck[gS->whoseTurn][1] = baron;
	gS->deck[gS->whoseTurn][2] = silver;
	gS->deck[gS->whoseTurn][3] = baron;
	gS->deck[gS->whoseTurn][4] = gold;

	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);

	if (gS->whoseTurn == 0) {
		actual = gS->deckCount[gS->whoseTurn];
	}

	return assertTrue(actual, expected);
}

//int adventurer_isDeckEmpty() {
//	struct gameState* actualGS = newGame();
//	struct gameState* expectedGS = newGame();
//
//	actualGS->whoseTurn = 0;
//	printf("whoseTurn set\n");
//	actualGS->deckCount[actualGS->whoseTurn] = 3;
//	printf("deckCount set\n");
//	//actualGS->discardCount = 3;
//	int i;
//	for (i = 0; i < 3; i++) {
//		printf("adding copper to actual discard\n");
//		actualGS->discard[actualGS->whoseTurn][i] = copper;
//	}
//
//	expectedGS->whoseTurn = 0;
//	printf("whoseTurn set\n");
//	expectedGS->deckCount[expectedGS->whoseTurn] = 3;
//	printf("deckCount set\n");
//	//expectedGS->discardCount = 0;
//	for (i = 0; i < 3; i++) {
//		printf("adding copper to expected deck\n");
//		expectedGS->deck[expectedGS->whoseTurn][i] = copper;
//	}
//
//	printf("before cardEffect\n");
//	cardEffect(adventurer, 0, 0, 0, actualGS, 0, 0);
//	printf("after cardEffect\n");
//	return assertObjectTrue(actualGS, expectedGS);
//}
//
//int adventurer_isCopper() {
//	struct gameState* actualGS = newGame();
//	struct gameState* expectedGS = newGame();
//
//	actualGS->whoseTurn = 0;
//	printf("whoseTurn set\n");
//	actualGS->deckCount[actualGS->whoseTurn] = 0;
//	printf("deckCount set\n");
//	//actualGS->discardCount = 3;
//	int i;
//	for (i = 0; i < 3; i++) {
//		printf("adding copper to actual discard\n");
//		actualGS->discard[actualGS->whoseTurn][i] = copper;
//	}
//
//	expectedGS->whoseTurn = 0;
//	printf("whoseTurn set\n");
//	expectedGS->deckCount[expectedGS->whoseTurn] = 3;
//	printf("deckCount set\n");
//	//expectedGS->discardCount = 0;
//	for (i = 0; i < 3; i++) {
//		printf("adding copper to expected deck\n");
//		expectedGS->hand[expectedGS->whoseTurn][i] = copper;
//	}
//
//	printf("before cardEffect\n");
//	cardEffect(adventurer, 0, 0, 0, actualGS, 0, 0);
//	printf("after cardEffect\n");
//	return assertObjectTrue(actualGS, expectedGS);
//}
//
//int adventurer_isSilver() {
//
//}
//
//int adventurer_isGold() {
//
//}
//
//int adventuer_isTreasure() {
//
//}
//
//int adventurer_notTreasure() {
//
//}
//
//int adventurer_noTreasure() {
//
//}
//

