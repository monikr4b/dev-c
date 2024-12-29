
/* sleep.c */

#include <stdio.h>
#include <unistd.h>

int main()
{
      printf("Wait while loading...");
      fflush(stdout);

      int x;

      x = 5;
      sleep(x); // Program will pause execution for x seconds
      printf(" Ok\n");

      return 0;
}
