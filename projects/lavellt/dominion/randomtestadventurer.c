// Tucker Lavell
// random test: Adventurer
#include "unittests.h"

//#define MAX_TESTS 1000
#define MAX_TESTS 1000000

// todo: make this into generic treasure counter using pile (int*) instead of gamestate
//int countNumTreasureCards(int currentPlayer, struct gameState *gS) {
//	int numTreasure = 0;
//
//	int i;
//	for (i = 0; i < gS->handCount[currentPlayer]; i++) {
//		if (gS->hand[currentPlayer][i] == copper ||
//			gS->hand[currentPlayer][i] == silver ||
//			gS->hand[currentPlayer][i] == gold) {
//			numTreasure++;
//		}
//	}
//
//	return numTreasure;
//}

int countNumTreasureCards(int pile, int size) {
	int numTreasure = 0;

	int i;
	for (i = 0; i < size; i++) {
		if (pile[i] == copper ||
			pile[i] == silver ||
			pile[i] == gold) {
			numTreasure++;
		}
	}

	return numTreasure;
}


//int rand_adventurer_treasuresDrawn() {
//
//}
//
//int rand_adventurer_discardCards() {
//
//}
//
//int rand_adventurer_cardsLeftInDeck() {
//
//}
//
//int rand_adventurer_treasuresDiscarded() {
//
//}

int main() {
	srand(time(NULL));
	struct gameState pre;
	int seed = 30;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize = 0;
	int handSize = 0;
	int totalTestsPassed = 0;
	int drawTreasureTestsFailed = 0;
	int discardTestsFailed = 0;
	int deckTestsFailed = 0;
	int discardTreasureTestsFailed = 0;
	int numTests = 4;
	//int numPassed = 0;

	int i;
	for (i = 0; i < MAX_TESTS; i++) {
		printf("Test #%d\n", i + 1);
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
		//pre.coins = countNumTreasureCards(currentPlayer, &pre);
		pre.coins = countNumTreasureCards(&pre.deck[currentPlayer], pre.deckCount[currentPlayer]);

		// create the object to modify (copy of pre), saves pre for comparison later
		struct gameState post;
		memcpy(&post, &pre, sizeof(struct gameState));
		
		// call adventurer, using post
		cardEffect(adventurer, 0, 0, 0, &post, handPos, 0);

		post.coins = countNumTreasureCards(&post.deck[currentPlayer], post.deckCount[currentPlayer]);

		// *** Test Cases *** 
		int numPassed = 0;
		// used for true/false flagging in if structure
		int allTestsPassed = 1;

		// Adv should add 2 treasures to the hand
		printf("1. Check Number of Treasures Drawn: ");
		if (!assertTrue(post.coins, pre.coins + 2)) {		
			drawTreasureTestsFailed++;
			allTestsPassed = 0;
		}

		numPassed++;

		printf("2. Check Number of Cards Discarded: ");
		// calc pre's potential discard size
		pre.discardCount[currentPlayer] = deckSize - post.deckCount[currentPlayer] - post.handCount[currentPlayer];
		if (!assertTrue(post.discardCount[currentPlayer], pre.discardCount[currentPlayer])) {
			discardTestsFailed++;
			allTestsPassed = 0;
		}

		numPassed++;

		printf("3. Check Number of Cards Left in Deck: ");
		// calc pre's potential deck size
		pre.deckCount[currentPlayer] = deckSize - post.handCount[currentPlayer] - post.discardCount[currentPlayer];
		if (!assertTrue(post.deckCount[currentPlayer], pre.deckCount[currentPlayer])) {
			deckTestsFailed++;
			allTestsPassed = 0;
		}

		numPassed++;

		printf("4. Check if Treasure(s) got Discarded: ");
		//int x;
		// calc number of treasures discarded just for debugging purposes
		/*int numTreasureDiscarded = 0;*/
		//for (x = 0; x < post.discardCount[currentPlayer]; x++) {
		//	if (post.discard[currentPlayer][x] == copper ||
		//		post.discard[currentPlayer][x] == silver ||
		//		post.discard[currentPlayer][x] == gold) {
		//		numTreasureDiscarded++;
		//	}
		//}
		if (!assertTrue(countNumTreasureCards(&post.discard[currentPlayer], post.discardCount[currentPlayer]), 0)) {
			discardTreasureTestsFailed++;
			allTestsPassed = 0;
		}

		numPassed++;

		// TODO: 5. check discard for adventurer
		
		if (allTestsPassed != 0) {
			printf("%d/%d: ", numPassed, numTests);
			if (assertTrue(allTestsPassed, 1)) {
				totalTestsPassed++;
			}
		}
	}

	printf("\n\n");
	printf("1. Number of Treasures Drawn to Hand Failed: %d/%d\n", drawTreasureTestsFailed, i);
	printf("2. Number of Cards Discarded Failed: %d/%d\n", discardTestsFailed, i);
	printf("3. Number of Cards Left in Deck Failed: %d/%d\n", deckTestsFailed, i);
	printf("4. Treasure(s) Discarded Tests Failed: %d/%d\n", discardTreasureTestsFailed, i);
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);


	return 0;
}

