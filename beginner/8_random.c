/* random.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int our_random_func(int max)
{
      int x; 

      x = rand() % max + 1; // rand() calculates a different random number every time it's called
      /* Modulo Operator :
      Returns the (integer) remainder of a division between the two inputs. The resulting number cannot be larger than the divisor minus 1 */

      return x;
}

int main()
{
      int random; 

      srand(getpid()); 
      // Seed of rand(), sets a number for rand's algorithm to start generating random numbers from
      // Get process ID system call, usually changes for every execution

      /* return 0; */
      // Would stop program execution in the middle of the function

      random = our_random_func(5);
      printf("%d\n", random);

      random = our_random_func(10);
      printf("%d\n", random);

      return 0;
}