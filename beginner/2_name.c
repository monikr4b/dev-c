
/* name.c */

#include <stdio.h>

int main()
{
      char name[32]; /* char: type for characters and strings */
      // A string is just an array of characters, in this case, "name" can support names up to 32 characters long

      printf("Hello, what is your name?\n");

      scanf("%s", &name); /* %s tells scanf to format for a string */
        // When using scanf(), place an ampersand "&" before the variable name.

      printf("Hello, %s!\n", name);
        // format string %s is replaced by variable's value

      return 0;
}
