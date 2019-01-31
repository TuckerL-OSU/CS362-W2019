#include "unittests.h"

int assertTrue(int actual, int expected) {
	if (actual == expected) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED - Actual: %d, Expected: %d\n", actual, expected);
		return 0;
	}
}

int assertObjectTrue(struct gameState* actual, struct gameState* expected) {
	if (actual->whoseTurn == expected->whoseTurn &&
		actual->deckCount == expected->deckCount) {
		int i;
		for (i = 0; i < 3; i++) {
			if (actual->hand[actual->whoseTurn][i] == expected->hand[expected->whoseTurn][i]) {
				continue;
			}
			else {
				printf("TEST FAILED\n");
				return 0;
			}
		}
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		return 0;
	}
}

