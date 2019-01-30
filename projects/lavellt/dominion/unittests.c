#include "unittests.h"

int assertTrue(int expected, int actual) {
	if (actual == expected) {
		printf("TEST SUCCESSFULLY COMPLETED\n");
		return 1;
	}
	else {
		printf("TEST FAILED\n");
		return 0;
	}
}

//int discardHand(struct gameState *gS) {
//
//}