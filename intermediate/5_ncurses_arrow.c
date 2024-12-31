/* ncurses.c - arrow */

#include <ncurses.h>

int main()
{
      int key, x, y;

      x = y = 5;

      initscr();

      keypad(stdscr, TRUE); // Enables the part of the keyboard right of Enter, F12, etc...
      noecho(); // Turns off automatic echoing of pressed keys to the screen

      while (key != 'q')
      {
            clear();
            move(0, 0);
            printw("Press left or right arrow - exit by pressing 'q'");

            move (y, x);
            printw("X");
            refresh();

            key = getch();


            if (key == KEY_LEFT) // KEY_LEFT is a #defined value in ncurses.h that refers to the left arrow key
            {
                  x--;
                  if (x < 0) { x = 0; } // Bounds checking done AFTER decrementing the value--will correct immediately if out of bounds
            }
            else if (key == KEY_RIGHT)
            {
                  x++;
                  if (x > 200) { x = 200; }
            }

            if (key == KEY_UP)
            {
                  y--;

                  if (y < 0) { y = 0; }
            }
            else if (key == KEY_DOWN)
            {
                  y++;

                  if (y > 200) { y = 200; }
            }
      }

      endwin();

      return 0;
}