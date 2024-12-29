/* pointers.c */

#include <stdio.h>
#include <string.h>

int main()
{
      char str[32];
      char *p; // This is a pointer, it hold the memory address of whatever it's equal to

      strncpy(str, "I like apples", 31);

      p = str; // Here, "p" points to the string "str", specifically, the first element or byte
      p++; // By incrementing the value of "p", we make it point to the next element and/or byte of the array 

      printf("%c\n", *p); // If we print the value of "p", we'll see it now points to an empty space, which corresponds to the second value of str[32]

      return 0;
}