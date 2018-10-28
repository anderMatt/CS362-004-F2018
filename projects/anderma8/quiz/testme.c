/**************************************************
Matthew Anderson
10/28/18
CS 362 - Random Testing Generator

Example of a random test generator. Goal is to
randomly generate characters and a string until
the desired output is encountered: "reset".
**************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


static const char *INPUT_SET = "[({ ax})]rest";
static const int TARGET_LENGTH = 5;

/*
Returns a random character from the possible input set.
*/
char inputChar()
{
    int index = rand() % strlen(INPUT_SET);
    return INPUT_SET[index];
}

/*
Returns a random string of length TARGET_LENGTH
using characters from the input set.
*/
char *inputString()
{
    char *generatedString = malloc(sizeof(char) * TARGET_LENGTH + 1);  // Need to allocate space for null-terminator.
    for(int i = 0; i < TARGET_LENGTH; i++) {
      generatedString[i] = inputChar();
    }
    generatedString[TARGET_LENGTH + 1] = '\0';  // malloc doesn't initialize any blocks.

    return generatedString;
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
