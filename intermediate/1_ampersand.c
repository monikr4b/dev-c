/* ampersand.c */

#include <stdio.h>

void addition(int *target, int x, int y) // We initialize a pointer to an integer in the parameters of the function.
{
      *target = x + y; // Changes the value stored at the memory address the pointer points to into the value of x + y

    /*
      target = x + y; // This tries to change the memory address the pointer holds, resulting in an error,
                         because a pointer must point to a valid memory address and not an int
    */
      return;
}

int main()
{
      int a, b, answer;

      a = 5; b = 15;

      addition(&answer, a, b); // By passing the address of a variable to a pointer, we alter the address it's pointing to
                               // Since *target now points to the address of answer, the function adds the values and stores them in the memory address of answer

      printf("%d", answer); // Thus, answer now holds the result of the addition

      return 0;
}