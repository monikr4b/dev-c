
/* if.c */

#include <stdio.h>

int main()
{
      int speed;

      printf("How fast are you driving (in km/h)?\n");
      scanf("%d", &speed);

      // See ~/dev/c/beginner/DOCS/statements.md for explanation:

      if (speed > 100) {
            printf("You are speeding! Please slow down...\n");
      }
      else if (speed > 80) {
            printf("You're driving at a nice speed, well done!\n");
      }
      else { 
            printf("You are driving too slowly! Please speed up...\n");
      }

      return 0;
}