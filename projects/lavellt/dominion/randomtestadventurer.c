// Tucker Lavell
// random test: Adventurer
#include "unittests.h"


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
	int numPlayers = rand() % (4 + 2);
	int curPlayer = 0;
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
	int coinCountBefore;
	int testPassed = 0;
	int drawTestFailed = 0;
	int discardTestFailed = 0;

	int i;
	for (i = 0; i < 1000000; i++) {
		// set up a game
		initializeGame(numPlayers, k, seed, &pre);
		// set a players turn, which player doesn't matter
		pre.whoseTurn = 0;
		int currentPlayer = pre.whoseTurn;
		deckSize = rand() % (MAX_DECK + 1);
		// just to prevent the hand from being bigger than the deck
		handSize = rand() % (deckSize + 1);

		// number of cards left in deck is total - number in hand
		pre.deckCount[0] = deckSize - handSize;
		pre.handCount[0] = handSize;

		// position of adventurer
		int handPos = rand() % handSize;

		//int j;
		//for (j = 0; j < numPlayers; j++) {
		
			int j;
			for (j = 0; j < pre.deckCount[currentPlayer]; j++) {
				int randomCard = rand() % (26 + 0);
				// attempt to stack the deck with some treasures just to be safe
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
					// else fill hand with a random kingdom card
					int randomK = rand() % (10);
					pre.deck[currentPlayer][j] = k[randomK];
				}
			}
		//}

		//for (m = 0; m < pre.handCount[curPlayer]; m++) {
		//	if (pre.hand[curPlayer][m] == copper || pre.hand[curPlayer][m] == silver || pre.hand[curPlayer][m] == gold) {
		//		coinCountBefore++;
		//	}
		//}

		// coins is unused so I am going to use it here for testing
		pre.coins = countNumTreasureCards(pre.whoseTurn, &pre);

		// create the object to do work on
		struct gameState post;
		memcpy(&post, pre, sizeof(struct gameState));
		
		//printf("Coin Count before: %d\n", coinCount);
		//printf("discard count before: %d\n", pre.discardCount[curPlayer]);
		//printf("deckSize: %d, deck: %d, and hand: %d\n", deckSize, pre.deckCount[0], pre.handCount[0]); 
		cardEffect(adventurer, 0, 0, 0, &post, handPos, 0);

		coinCount = 0;

		//for (m = 0; m < pre.handCount[curPlayer]; m++) {
		//	if (pre.hand[curPlayer][m] == copper || pre.hand[curPlayer][m] == silver || pre.hand[curPlayer][m] == gold) {
		//		coinCount++;
		//	}
		//}

		post.coins += countNumTreasureCards(post.whoseTurn, &post);

		//printf("Coin Count after: %d\n", coinCount);
		//printf("discard count after: %d\n", pre.discardCount[curPlayer]);
		discardCopper = 0;
		discardSilver = 0;
		discardGold = 0;
		for (x = 0; x < post.discardCount[curPlayer]; x++) {
			if (post.discard[curPlayer][x] == copper) {
				discardCopper++;
			}
			else if (post.discard[curPlayer][x] == silver) {
				discardSilver++;
			}
			else if (post.discard[curPlayer][x] == gold) {
				discardGold++;
			}
		}
		int passed = 1;
		if (post.coins > (pre.coins + 2)) {
			printf("Too many cards drawn: Test Failed\n\n");
			drawTestFailed++;
			passed = 0;
		}

		if (post.coins < pre.coins) {
			printf("Fewer cards exist in hand than were first present: Test Failed\n\n");
			drawTestFailed++;
			passed = 0;
		}
		if (discardCopper != 0) {
			printf("Copper was discarded: Test Failed\n\n");
			discardTestFailed++;
			passed = 0;
		}

		if (discardSilver != 0) {
			printf("Silver was discarded: Test Failed\n\n");
			discardTestFailed++;
			passed = 0;
		}

		if (discardGold != 0) {
			printf("Gold was discarded: Test Failed\n\n");
			discardTestFailed++;
			passed = 0;
		}

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

