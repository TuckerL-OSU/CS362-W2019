#include "unittests.h"

int assertTrue(int actual, int expected) {
	if (actual == expected) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED - Actual:%d, Expected:%d\n", actual, expected);
		return 0;
	}
}

//int discardHand(struct gameState *gS) {
//
//}