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

// check to see if the cards we kept were treasures and how many
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

	printf("Test 1\n");
	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);
	printf("leave cardeffect 1\n");

	int i;
	for (i = 0; i < gS->handCount[gS->whoseTurn]; i++) {
		if (gS->hand[gS->whoseTurn][i] == copper ||
			gS->hand[gS->whoseTurn][i] == silver ||
			gS->hand[gS->whoseTurn][i] == gold) {
			actual++;
		}
	}

	printf("1. Check Number of Treasures Drawn: ");
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

	printf("Test 2\n");
	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);
	printf("leave cardeffect 2\n");


	if (gS->whoseTurn == 0) {
		actual = gS->discardCount[gS->whoseTurn];
	}

	printf("2. Check Number of Cards Discarded: ");
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

	printf("Test 3\n");
	cardEffect(adventurer, 0, 0, 0, gS, 0, 0);
	printf("leave cardeffect 3\n");

	if (gS->whoseTurn == 0) {
		actual = gS->deckCount[gS->whoseTurn];
	}

	printf("3. Check Number of Cards left in deck: ");
	return assertTrue(actual, expected);
}