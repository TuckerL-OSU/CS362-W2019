// Tucker Lavell
// random test: Adventurer
#include "unittests.h"

#define MAX_TESTS 1000

int countNumTreasureCards(int currentPlayer, struct gameState *gS) {
	int numTreasure = 0;

	int i;
	for (i = 0; i < gS->handCount[currentPlayer]; i++) {
		if (gS->hand[currentPlayer][i] == copper || gS->hand[currentPlayer][i] == silver || gS->hand[currentPlayer][i] == gold) {
			numTreasure++;
		}
	}

	return numTreasure;
}

int main() {
	srand(time(NULL));
	struct gameState pre;
	int seed = 1000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize;
	int handSize;
	int m;
	int coinCount;
	int x;
	int discardCopper;
	int discardSilver;
	int discardGold;
	int testPassed = 0;
	int drawTestFailed = 0;
	int discardTestFailed = 0;

	int i;
	for (i = 0; i < MAX_TESTS; i++) {
		printf("Test #%d\n", i);
		// set up a game
		initializeGame(numPlayers, k, seed, &pre);
		// set a players turn, which player doesn't matter
		pre.whoseTurn = currentPlayer;
		deckSize = rand() % (MAX_DECK + 1);
		// just to prevent the hand from being bigger than the deck
		handSize = rand() % (deckSize + 1);

		// number of cards left in deck is total - number in hand
		pre.deckCount[0] = deckSize - handSize;
		pre.handCount[0] = handSize;

		// position of adventurer
		int handPos = 0;
		
		int j;
		for (j = 0; j < pre.deckCount[currentPlayer]; j++) {
			// choose a card from 0-26 (matches enum)
			int randomCard = rand() % (27 + 1) - 1;
			// attempt to "load" the deck with some treasures just to be safe
			if (randomCard == copper) {
				pre.deck[currentPlayer][j] = copper;
			}
			else if (randomCard == silver) {
				pre.deck[currentPlayer][j] = silver;
			}
			else if (randomCard == gold) {
				pre.deck[currentPlayer][j] = gold;
			}
			else {
				// else fill deck with a random kingdom card
				int randomK = rand() % (10 + 1) - 1;
				pre.deck[currentPlayer][j] = k[randomK];
			}
		}

		// coins is unused so I am going to use it here for testing
		pre.coins = countNumTreasureCards(currentPlayer, &pre);

		// create the object to modify, saves pre for comparison later
		struct gameState post;
		memcpy(&post, &pre, sizeof(struct gameState));
		
		// call adventurer, using post
		cardEffect(adventurer, 0, 0, 0, &post, handPos, 0);

		post.coins += countNumTreasureCards(post.whoseTurn, &post);

		int passed = 1;
		// Adv should add 2 treasures to the hand
		/*if (post.coins > (pre.coins + 2)) {*/
		printf("1. Check Number of Treasures Drawn: ");
		if (!assertTrue(post.coins, pre.coins + 2)) {		
			drawTestFailed++;
			passed = 0;
		}

		//if (post.coins <= pre.coins) {
		//	printf("Not enough treasures drawn: Test Failed\n");
		//	drawTestFailed++;
		//	passed = 0;
		//}

		printf("2. Check Number of Cards Discarded: ");
		// calc pre's potential discard size
		pre.discardCount[currentPlayer] = deckSize - post.deckCount[currentPlayer] - post.handCount[currentPlayer];
		if (!assertTrue(post.discardCount[currentPlayer], pre.discardCount[currentPlayer])) {
			discardTestFailed++;
			passed = 0;
		}

		printf("3. Check Number of Cards Left in Deck: ");
		// calc pre's potential deck size
		pre.deckCount[currentPlayer] = deckSize - post.handCount[currentPlayer] - post.discardCount[currentPlayer];
		if (!assertTrue(post.deckCount[currentPlayer], pre.deckCount[currentPlayer] - )) {
			discardTestFailed++;
			passed = 0;
		}

		//discardCopper = 0;
		//discardSilver = 0;
		//discardGold = 0;
		//for (x = 0; x < post.discardCount[currentPlayer]; x++) {
		//	if (post.discard[currentPlayer][x] == copper) {
		//		discardCopper++;
		//	}
		//	else if (post.discard[currentPlayer][x] == silver) {
		//		discardSilver++;
		//	}
		//	else if (post.discard[currentPlayer][x] == gold) {
		//		discardGold++;
		//	}
		//}
		//
		//if (discardCopper != 0) {
		//	printf("Copper was discarded: Test Failed\n\n");
		//	discardTestFailed++;
		//	passed = 0;
		//}

		//if (discardSilver != 0) {
		//	printf("Silver was discarded: Test Failed\n\n");
		//	discardTestFailed++;
		//	passed = 0;
		//}

		//if (discardGold != 0) {
		//	printf("Gold was discarded: Test Failed\n\n");
		//	discardTestFailed++;
		//	passed = 0;
		//}

		if (passed == 1) {
			printf("All Tests: Passed\n\n");
			testPassed++;
		}

	}

	printf("\n\n");
	printf("# of Tests Passed: %d\n", testPassed);
	printf("# of Cards Drawn To Hand Failed: %d\n", drawTestFailed);
	//printf("# of Smithy Discarded Fails: %d\n\n", discardTestFailed);

	return 0;
}

