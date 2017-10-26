#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// TODO: rewrite this function
	char random_char;

	int min = 32;	//ascii min 91 = '['
	int max = 94;	//91 + 35 = 126 -- ascii range max '~'

	//ascii chars from 91 - 126
	random_char = rand() % max + min;

	return random_char;    
}

char *inputString()
{
	// TODO: rewrite this function


	//set up array of letters that are used in string
	const char setLetters[] = "rest";
	int setLettersLength = sizeof(setLetters) - 1;

	//uncomment below to test iterations for all lowercase char
	//const char setLetters[] = "abcdefghijklmnopqrstuvwxyz";
	//int setLettersLength = sizeof(setLetters) - 1;

	//array to hold random letters from the set array
	static char array[6];

	char random_char;

	int i;
	for (i = 0; i < 5; i++) {
		random_char = setLetters[rand() % setLettersLength];
		array[i] = random_char;
	}
	array[5] = '\0';
	return array;

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
    if (c == ' '&& state == 3) state = 4;
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
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
