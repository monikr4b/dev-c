/* ncurses.c ; x and y */

#include <ncurses.h>
#include <unistd.h>

int main()
{
      int x, y;

      initscr();
      clear();

      getyx(stdscr, y, x); // stdscr is the screen created by the firs initscr() call
      printw("x = %d\ny = %d", x, y); refresh();

      y = 5;       //   To move text around the screen, first redefine the y and x coordinates
      x = 10;      //   Then call the move function with the y && x coordinates as arguments
      move(x, y);  //   y must come before x, in this case, they're swapped, so we end up with y = 10 and x = 5

      printw("Over here!"); refresh();

      getch();

      endwin();

      return 0;
}
