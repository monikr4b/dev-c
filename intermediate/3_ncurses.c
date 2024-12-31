/* ncurses.c */

#include <ncurses.h>
#include <unistd.h>

int main()
{
      char letter;

      initscr(); // Initializes a screen--hands the whole terminal to ncurses

      printw("Press any key: "); refresh(); 
      // printw() is the curses equivalent of printf, it doesn't need to end on a newline because the buffer works differently to stdout's
      // Calling refresh() is needed to show what we've altered in the screen since the last refresh--in this case, initscr().

      letter = getch(); // Same as getchar() but can also take inputs like ->, Esc, etc... 
      clear(); // Wipes out what has been drawn on the screen

      printw("You entered %c", letter);
      refresh();
      for (int i = 0; i <= 3; i++)
      {
            sleep(1);
            printw("."); refresh();
      }

      clear();

      printw("Press any key to exit..."); refresh();
      getch();

      endwin(); // Closes the window

      return 0;
}