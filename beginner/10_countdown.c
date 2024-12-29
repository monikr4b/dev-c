/* countdown.c */

#include <stdio.h>
#include <unistd.h>

int main()
{
      int number;
      number = 6;

      while (1)
      {
            number--; // Reduces number by 1 for every iteration

            if (number == 3) { continue; }
            // Skips to the next iteration

            printf("%d\n", number);

            sleep(1);
            if (number <= 0) { break; }
            // Breaks out of the currently running loop...
      }
      // ...resumes execution here

      printf("Success!\n");

      return 0;
}