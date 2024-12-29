
/* while.c */

#include <stdio.h>

int main()
{
      int x;
      x = 0;

      while (x == 0) {
      // While loop: While a condition is true, keeps looping over a piece of code

      printf("Press 1 to quit.\n");
      scanf("%d", &x);
      }

      return 0;
}