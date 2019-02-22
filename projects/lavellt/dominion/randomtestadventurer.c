// Tucker Lavell
// random test: Adventurer
#include "unittests.h"

// TODO: make this into generic treasure counter using pile (int*) instead of gamestate
int countNumTreasureCards(int currentPlayer, struct gameState *gS) {
	int numTreasure = 0;

	int i;
	for (i = 0; i < gS->handCount[currentPlayer]; i++) {
		if (gS->hand[currentPlayer][i] == copper ||
			gS->hand[currentPlayer][i] == silver ||
			gS->hand[currentPlayer][i] == gold) {
			numTreasure++;
		}
	}

	return numTreasure;
}

//int countNumTreasureCards(int *pile, int size) {
//	int numTreasure = 0;
//
//	int i;
//	for (i = 0; i < size; i++) {
//		if (pile[i] == copper ||
//			pile[i] == silver ||
//			pile[i] == gold) {
//			numTreasure++;
//		}
//	}
//
//	return numTreasure;
//}

int main() {
	srand(time(NULL));
	// game vars
	struct gameState* pre = newGame();;
	int seed = 100000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize = 0;
	int handSize = 0;

	// test vars
	int totalTestsPassed = 0;
	//int numCases = 4;
	int drawTreasureTestsFailed = 0;
	int discardTestsFailed = 0;
	int deckTestsFailed = 0;
	int discardTreasureTestsFailed = 0;

	int i;
	for (i = 0; i < MAX_TESTS; i++) {
		printf("Test #%d\n", i + 1);
		// set up a game
		initializeGame(numPlayers, k, seed, pre);
		// set a players turn, which player doesn't matter
		pre->whoseTurn = currentPlayer;
		deckSize = rand() % (MAX_DECK + 1);
		// just to prevent the hand from being bigger than the deck
		handSize = rand() % (deckSize + 1);

		// number of cards left in deck is total - number in hand
		pre->deckCount[currentPlayer] = deckSize - handSize;
		pre->handCount[currentPlayer] = handSize;

		// position of adventurer
		int handPos = 0;
		
		int j;
		for (j = 0; j < pre->deckCount[currentPlayer]; j++) {
			// choose a card from 0-26 (matches enum)
			int randomCard = rand() % 27;
			// attempt to "load" the deck with some treasures just to be safe
			if (randomCard == copper) {
				pre->deck[currentPlayer][j] = copper;
			}
			else if (randomCard == silver) {
				pre->deck[currentPlayer][j] = silver;
			}
			else if (randomCard == gold) {
				pre->deck[currentPlayer][j] = gold;
			}
			else {
				// else fill deck with a random kingdom card
				int randomK = rand() % 10;
				pre->deck[currentPlayer][j] = k[randomK];
			}
		}

		// coins is unused so I am going to use it here for testing
		pre->coins = countNumTreasureCards(currentPlayer, pre);
		//pre->coins = countNumTreasureCards(pre->deck[currentPlayer], pre->deckCount[currentPlayer]);

		
		struct gameState post;
		memcpy(&post, pre, sizeof(struct gameState));
		
		// call adventurer, using post
		cardEffect(adventurer, 0, 0, 0, &post, handPos, 0);

		post.coins = countNumTreasureCards(currentPlayer, &post);
		//post.coins = countNumTreasureCards(post.deck[currentPlayer], post.deckCount[currentPlayer]);

		// *** Test Cases *** 
		// used for true/false flagging in if structure
		int allCasesPassed = 1;

		// Adv should add 2 treasures to the hand
		printf("1. Check Number of Treasures Drawn: ");
		if (!assertTrue(post.coins, pre->coins + 2)) {		
			drawTreasureTestsFailed++;
			allCasesPassed = 0;
		}

		printf("2. Check Number of Cards Discarded: ");
		// calc pre's potential discard size
		// this at least ensures that even with a failed number of
		// treasures drawn, the card is still handling card management
		pre->discardCount[currentPlayer] = deckSize - post.deckCount[currentPlayer] - post.handCount[currentPlayer];
		if (!assertTrue(post.discardCount[currentPlayer], pre->discardCount[currentPlayer])) {
			discardTestsFailed++;
			allCasesPassed = 0;
		}

		printf("3. Check Number of Cards Left in Deck: ");
		// calc pre's potential deck size
		pre->deckCount[currentPlayer] = deckSize - post.handCount[currentPlayer] - post.discardCount[currentPlayer];
		if (!assertTrue(post.deckCount[currentPlayer], pre->deckCount[currentPlayer])) {
			deckTestsFailed++;
			allCasesPassed = 0;
		}
		
		printf("4. Check if Treasure(s) got Discarded: ");
		int x;
		 //calc number of treasures discarded just for debugging purposes
		int numTreasureDiscarded = 0;
		for (x = 0; x < post.discardCount[currentPlayer]; x++) {
			if (post.discard[currentPlayer][x] == copper ||
				post.discard[currentPlayer][x] == silver ||
				post.discard[currentPlayer][x] == gold) {
				numTreasureDiscarded++;
			}
		}

		//if (!assertTrue(countNumTreasureCards(post.discard[currentPlayer], post.discardCount[currentPlayer]), 0)) {
		if (!assertTrue(numTreasureDiscarded, 0)) {
			discardTreasureTestsFailed++;
			allCasesPassed = 0;
		}

		// TODO: 5. check discard for adventurer
		
		if (allCasesPassed == 1) {
			totalTestsPassed++;
		}
	}

	printf("\nAdventurer Summary\n");
	printf("Number of Tests Fully Passed: %d/%d\n", totalTestsPassed, i);
	printf("1. Number of Treasures Drawn to Hand Failed: %d\n", drawTreasureTestsFailed);
	printf("2. Number of Cards Discarded Failed: %d\n", discardTestsFailed);
	printf("3. Number of Cards Left in Deck Failed: %d\n", deckTestsFailed);
	printf("4. Treasure(s) Discarded Tests Failed: %d\n", discardTreasureTestsFailed);

	return 0;
}

