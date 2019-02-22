#ifndef _UNITTESTS_H
#define _UNITTESTS_H

#define MAX_TESTS 1000000

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

int assertTrue(int, int);
int assertObjectTrue(struct gameState*, struct gameState*);

#endif