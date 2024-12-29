/* fork.c */

#include <stdio.h>
#include <unistd.h>

int main()
{
      FILE *fptr; // FILE is a data type used to work with files, so we're initializing a pointer "fptr" with type FILE

      int x = fork(); // By forking the program, we create two simultaneous instances of it
                      // x will be equal to the process ID of the parent process and 0 in the child process

      while (1)
      {
            if (x != 0)
            {
                  fptr = fopen("fork.txt", "a");
                  fprintf(fptr, "Printing from the parent process...\n");
                  fclose(fptr);
                  sleep(1);

                  /*   What's going on here?
                  *
                  *   First, we make *fptr equal to the function fopen(), which takes two arguments and returns a FILE pointer.
                  *   Basically, we're doing something like *a = *b
                  *   As for the arguments, the first is a file name and the second is a string that defines the operation we'll be performing,
                  *   in this case, "a" for "append"
                  *
                  *   fprintf() works in the same way as printf() but we have to specify the file we're writing to as a first argument
                  *
                  *   fclose() closes a file stream, taking the file pointer as its only argument.
                  *   - A stream is an abstraction that allows us to manage data flow (input, output or both)
                  *   - Streams have buffers, which are a way to improve performance by temporarily storing data before transfering or processing it
                  */
            }
            else if (x == 0)
            {
                  fptr = fopen("fork.txt", "a");
                  fprintf(fptr, "Printing from the child process...\n");
                  fclose(fptr);
                  sleep(1);
            }
      }

      return 0;
}
