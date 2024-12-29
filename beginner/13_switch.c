/* switch.c */

#include <stdio.h>

int main()
{
      int x;

      printf("Choose between 1 apple, 2 pears or 3 bananas: ");
      scanf("%d", &x);

      switch (x)
      {
            case 1:
                  printf("Apples\n");
                  break;
            case 2:
                  printf("Pears\n");
                  break;
            case 3:
                  printf("Bananas\n");
                  break;
            default:
                  printf("Something else...\n");
      }

      /*
      if (x == 1)
            printf("Apples\n");
      else if (x == 2)
            printf("Pears\n");
      else if (x == 3)
            printf("Bananas\n");
      else
            printf("Something else...\n");
      */

      return 0;
}
