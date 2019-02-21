// Tucker Lavell
// random test: Smithy
#include "unittests.h"

#define MAX_TESTS 1000
//#define MAX_TESTS 1000000

int main() {
	srand(time(NULL));
	struct gameState pre;
	int seed = 100000;
	int numPlayers = 2;
	int curPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize;
	int handSize;
	int handPos;
	int deckBefore;
	int deckAfter;
	int handBefore;
	int handAfter;
	int discardBefore;
	int discardAfter;
	int i;
	int deckFailure = 0;
	int handFailure = 0;
	int discardFailure = 0;
	int testPassed = 0;
	int passed;

	//randomize hand size
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

		// position of smithy
		int handPos = 0;

		//personal checks
		deckBefore = G.deckCount[0];
		//printf("deck before %d\n", deckBefore);
		handBefore = G.handCount[0];
		//printf("Hand before %d\n",handBefore);
		discardBefore = G.playedCardCount;
		//printf("Discard before %d\n", discardBefore);


		cardEffect(smithy, 0, 0, 0, &G, handPos, 0);

		deckAfter = G.deckCount[0];
		//printf("deck after %d\n", deckAfter);
		handAfter = G.handCount[0];
		//printf("hand After %d\n", handAfter);
		discardAfter = G.playedCardCount;
		//printf("Discard After %d\n\n", discardAfter);

		passed = 1;

		if (handAfter != (handBefore + 2)) {
			printf("Incorrect amount of cards drawn: Test Failed\n\n");
			handFailure++;
			passed = 0;
		}

		if (deckAfter != (deckBefore - 3)) {
			printf("Incorrect number of cards removed from deck: Test Failed\n\n");
			deckFailure++;
			passed = 0;
		}

		if (discardAfter != (discardBefore + 1)) {
			printf("Smithy Not Discarded after use: Test Failed\n\n");
			discardFailure++;
			passed = 0;
		}

		if (passed == 1) {
			printf("All Tests Passed!! Horray lucky us!\n\n");
			testPassed++;
		}

	}

	printf("\n\n");
	printf("# of Tests Passed: %d\n", testPassed);
	printf("# of Cards Drawn To Hand Failed: %d\n", handFailure);
	printf("# of Smithy Discarded Fails: %d\n\n", discardFailure);

	return 0;
}