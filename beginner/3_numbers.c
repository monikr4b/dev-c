/* numbers.c */

#include <stdio.h>

int main()
{
      int x, y, answer;
      // int y;
      // int answer; also works

      printf("Select a number:\n");
      scanf("%d", &x); 
      // %d stands for "decimal" (base 10)

      printf("Select another number:\n");
      scanf("%d", &y);

      answer = x + y;

      printf("The result of adding both is: %d\n", answer);

      return 0;
}
