/* for.c */

#include <stdio.h>
#include <assert.h>

#define FLUSH fflush(stdout) // Creates an alias for anything you want, conventionally the name is in all uppercase

void multi(int i, int t) // Void function: doesn't return a value  |  Also called a procedure
{
      int result = i * t;

      printf("%d * %d = %d\n",
            i, t, result);
}

int main()
{
      int table_numb;

      printf("Multiplication table between 1 and 12: "); FLUSH;
      scanf("%d", &table_numb);

      assert( (table_numb < 13) && (table_numb > 0) ); // Exits the program if conditions aren't met

      for (int i = 1; i < 13; i++) {
            multi(table_numb, i);
            /* Starting out with i = 1, repeatedly call the function, increasing the value of i by one after each call
            until i = 13, stopping when it reaches that value
            */
      }

      return 0;
}
