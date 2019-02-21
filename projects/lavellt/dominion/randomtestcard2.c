// Tucker Lavell
// random test: Smithy
#include "unittests.h"

//#define MAX_TESTS 1000
//#define MAX_TESTS 1000000

int main() {
	srand(time(NULL));
	// game vars
	struct gameState* pre = newGame();
	int seed = 100000;
	int numPlayers = 2;
	int currentPlayer = 0;
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy };
	int deckSize = 0;
	int handSize = 0;

	// test vars
	int totalTestsPassed = 0;
	//int numCases = 3;
	int cardsInDeckFailed = 0;
	int cardsInHandFailed = 0;
	int discardSmithyFailed = 0;

	int i;
	for (i = 0; i < MAX_TESTS; i++)

	return 0;
}