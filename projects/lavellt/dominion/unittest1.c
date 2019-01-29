#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS "TEST  SUCCESSFULLY COMPLETED"
#define FAILURE "TEST FAILED"


int main() {

	// play card
	struct gameState* gS = newGame();
	
	int expected = -1;
	int actual = playCard(0, 0, 0, 0, gS);

	if (actual == expected) {
		std::cout << SUCCESS << endl;
	}
	else {
		std::cout << FAILURE << endl;
	}

}