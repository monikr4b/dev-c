/* triangle.c */

#include <stdio.h>

int area; // We declare a global variable to use in two functions without declaring it twice

int area_triangle(int base, int height) // We initialize both variables as parameters
{
      area = (base * height) / 2;

      return area;
      // Ends the function and returns a value--in this case, a--whose type is determined by the function declaration
}

int main()
{
      int b, h;

      printf("Base: ");
      fflush(stdout);
      /* 
      Messages might not be shown on screen without a newline character because they're sitting in a buffer
      When waiting for user input without a newline, it's good practice to flush the buffer so that the data is printed to the screen immediately after printf() is read
      */
      scanf("%d", &b);

      printf("Height: ");
      fflush(stdout);
      scanf("%d", &h);

      int tri_area = area_triangle(b, h);
      /* Here we call area_triangle() with two arguments: b and h
      'base' and 'height' in area_triangle() have empty values because we didn't declare them, so we're forced to pass them as arguments
      In this case, we pass the values of b and h to 'base' and 'height', respectively */

      printf("The area of your triangle is %d\n", tri_area);
      /* It's also possible to directly print the function's output:
      printf("The area of your triangle is %d\n", area_triangle(b, h)); */

      return 0;
}
