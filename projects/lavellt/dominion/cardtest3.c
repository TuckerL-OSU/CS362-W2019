// Tucker Lavell
// card test 3: feast
#include "unittests.h"

int feast_gainCard();
//int feast_checkFeastIsGone();
//int feast_cardCost();


int main() {
	int passed = 0;
	int numTests = 3;

	passed += feast_gainCard();
	//passed += feast_checkFeastIsGone();
	//passed += feast_cardCost();

	printf("%d/%d Feast Card Tests Passed.\n", passed, numTests);
}

int feast_gainCard() {
	struct gameState* gS = newGame();

	int expected = duchy;
	int actual = -1;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 2;
	gS->hand[gS->whoseTurn][0] = feast;
	gS->hand[gS->whoseTurn][1] = gold;

	gS->deckCount[gS->whoseTurn] = 0;
	gS->discardCount[gS->whoseTurn] = 0;

	// just to make sure nothing is contaminated by passing expected
	int card = duchy;
	gS->supplyCount[card] = 1;
	printf("entering cardEffect\n");
	cardEffect(feast, card, 0, 0, gS, 0, 0);

	// since discard was originally none, we know the first card
	// in the discard pile will be the chosen card.
	printf("whoseTurn: %d\n", gS->whoseTurn);
	if (gS->whoseTurn == 0) {
		printf("checking discard\n");
		actual = gS->discard[gS->whoseTurn][0];
	}
	printf("asserting\n");
	return assertTrue(actual, expected);
}


//int feast_checkFeastIsGone() {
//
//}


//int feast_cardCost() {
//
//}
//
//int feast_tryOverCostCard() {
//
//}
//
//int feast_buyProvince() {
//
//}