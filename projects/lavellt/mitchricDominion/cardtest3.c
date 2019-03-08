// Tucker Lavell
// card test 3: feast
#include "unittests.h"

int feast_gainCard();
int feast_tryOverCostCard();
int feast_checkFeastIsGone();

int main() {
	int passed = 0;
	int numTests = 3;

	passed += feast_gainCard();
	passed += feast_tryOverCostCard();
	passed += feast_checkFeastIsGone();

	printf("%d/%d Feast Card Tests Passed.\n", passed, numTests);
}

// check to make sure the chosen card was picked up
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
	cardEffect(feast, card, 0, 0, gS, 0, 0);

	// since discard was originally none, we know the first card
	// in the discard pile will be the chosen card.
	if (gS->whoseTurn == 0) {
		actual = gS->discard[gS->whoseTurn][0];
	}

	printf("1. Check that chosen Card was Picked Up: ");
	return assertTrue(actual, expected);
}

// check the cost of a gained card. Since duchy was bought successfully in
// the last test, I am going to test a higher priced card, because I know
// it will trigger my bug. This will pass, but it should fail
//int feast_tryOverCostCard() {
//	struct gameState* gS = newGame();
//
//	// gold cost is 6 which is higher than should be for feast
//	int expected = gold;
//	int actual = -1;
//
//	gS->whoseTurn = 0;
//	gS->handCount[gS->whoseTurn] = 2;
//	gS->hand[gS->whoseTurn][0] = feast;
//	gS->hand[gS->whoseTurn][1] = silver;
//
//	gS->deckCount[gS->whoseTurn] = 0;
//	gS->discardCount[gS->whoseTurn] = 0;
//
//	// just to make sure nothing is contaminated by passing expected
//	int card = gold;
//	gS->supplyCount[card] = 1;
//	cardEffect(feast, card, 0, 0, gS, 0, 0);
//
//	// since discard was originally none, we know the first card
//	// in the discard pile will be the chosen card.
//	if (gS->whoseTurn == 0) {
//		actual = gS->discard[gS->whoseTurn][0];
//	}
//
//	printf("2. Try to Buy Overpriced Card: ");
//	return assertTrue(actual, expected);
//}
int feast_tryOverCostCard() {
	struct gameState* gS = newGame();
	//time_t start = time(NULL);
	//time_t end = 0;
	//time_t waitTime = 2; // wait 2 seconds

	//end = start + waitTime;

	// gold cost is 6 which is higher than should be for feast
	int expected = 3;
	int actual = -1;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 2;
	gS->hand[gS->whoseTurn][0] = feast;
	gS->hand[gS->whoseTurn][1] = silver;

	gS->deckCount[gS->whoseTurn] = 0;
	gS->discardCount[gS->whoseTurn] = 0;

	// just to make sure nothing is contaminated by passing expected
	int card = gold;
	gS->supplyCount[card] = 1;

	// added this to account for infinite loop
	actual = cardEffect(feast, card, 0, 0, gS, 0, 0);
	
	//if (strcmp(stdout, "That card is too expensive!\n") == 0) {
	//	actual = 0;
	//}

	// since discard was originally none, we know the first card
	// in the discard pile will be the chosen card.
	//if (gS->whoseTurn == 0) {
	//	actual = gS->discard[gS->whoseTurn][0];
	//}

	printf("2. Try to Buy Overpriced Card: ");
	return assertTrue(actual, expected);
}

// check to make sure feast is not in any piles (aka trashed)
int feast_checkFeastIsGone() {
	struct gameState* gS = newGame();

	// gold cost is 6 which is higher than should be for feast
	int expected = 0;
	int actual = -1;

	gS->whoseTurn = 0;
	gS->handCount[gS->whoseTurn] = 2;
	gS->hand[gS->whoseTurn][0] = feast;
	gS->hand[gS->whoseTurn][1] = silver;

	gS->deckCount[gS->whoseTurn] = 0;
	gS->discardCount[gS->whoseTurn] = 0;
	gS->playedCardCount = 0;

	// just to make sure nothing is contaminated by passing expected
	int card = duchy;
	int i;
	// set supply counts to 0 for testing later
	for (i = 0; i < (treasure_map + 1); i++) {
		// if it is duchy give it 1 for the sake of run
		if (i == card) {
			gS->supplyCount[i] = 1;
		}
		else {
			gS->supplyCount[i] = 0;
		}
	}
	cardEffect(feast, card, 0, 0, gS, 0, 0);

	// since discard was originally none, we know the first card
	// in the discard pile will be the chosen card.
	if (gS->whoseTurn == 0) {
		// check supply piles for anything > 0, indicate feast/problem
		for (i = 0; i < (treasure_map + 1); i++) {
			if (gS->supplyCount[i] != 0) {
				actual++;
			}
		}
		// check if there is a feast in the hand
		for (i = 0; i < gS->handCount[gS->whoseTurn]; i++) {
			if (gS->hand[gS->whoseTurn][i] == feast) {
				actual++;
			}
		}
		// check discard for feast
		for (i = 0; i < gS->discardCount[gS->whoseTurn]; i++) {
			if (gS->discard[gS->whoseTurn][i] == feast) {
				actual++;
			}
		}
		// check deck for feast
		for (i = 0; i < gS->deckCount[gS->whoseTurn]; i++) {
			if (gS->deck[gS->whoseTurn][i] == feast) {
				actual++;
			}
		}
		// check played cards for feast
		for (i = 0; i < gS->playedCardCount; i++) {
			if (gS->playedCards[i] == feast) {
				actual++;
			}
		}
	}

	printf("3. Check if Feast was Trashed: ");
	return assertTrue(actual, expected);
}
