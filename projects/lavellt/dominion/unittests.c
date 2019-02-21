#include "unittests.h"

int assertTrue(int actual, int expected) {
	if (actual == expected) {
		printf("TEST SUCCESSFULLY COMPLETED - Actual: %d, Expected: %d\n", actual, expected);
		return 1;
	}
	else {
		printf("TEST FAILED - Actual: %d, Expected: %d\n", actual, expected);
		return 0;
	}
}

int assertObjectTrue(struct gameState* actual, struct gameState* expected) {
	printf("in assertObjectTrue\n");
	if (actual->whoseTurn == expected->whoseTurn &&
		actual->deckCount[actual->whoseTurn] == expected->deckCount[expected->whoseTurn]) {
		printf("after if\n");
		int i;
		for (i = 0; i < 3; i++) {
			printf("testing hand hand equality in for loop\n");
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

