// Tucker Lavell
// CS362 - Winter 2019
// Random Testing Quiz
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// generate random char
char inputChar()
{
    // TODO: rewrite this function
	// includes multiple symbols, and lowercase letters
    return (char)((rand() % (126 - 32 + 1)) + 32);
}

// generate random string
char *inputString()
{
    // TODO: rewrite this function
	char str[6];

	int i;
	for (i = 0; i < 5; i++) {
	// get the decimal value of the letter
		int x = (rand() % (116 - 101 + 1)) + 101;
		// convert the decimal into its correct char
		char c = (char)x;
		// set the current string element to the new letter
		str[i] = c;
	}

	// null terminate string
	str[5] = '\0';

	char *string = str;

    return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
	if (tcCount >= 100000) {
		printf("100k tests stopping");
		exit(200);
	}
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
