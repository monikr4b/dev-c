
/* dicegame.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int bet()
{
      printf("\nEnter your betting amount (€): ");
      fflush(stdout);
      int betVal; scanf("%d", &betVal);

      return betVal;
}

int bankruptcy()
{
      printf("You're all out of cash. You're a failure.\n");

      printf("Exiting...");
      sleep(2);

      return 0;
}

int user_guess()
{
      printf("\nGuess the number the dice will land on (between 1-6).\nIf you wish to quit the game, enter 0.\n\n");
      sleep(1);

      printf("I think the dice will land on ");
      fflush(stdout);
      int guessVal; scanf("%d", &guessVal);

      if (guessVal == 0) {
            return guessVal;
      }
      while (guessVal > 6 || guessVal < 0) {
            printf("Your number isn't between 1 and 6, re-enter it: ");
            fflush(stdout);
            scanf("%d", &guessVal);
      }

      sleep(2);

      return guessVal;
}

int dice_roll()
{
      printf("\nThrowing the dice...\n");

      int numDice = rand() % 6 + 1;

      sleep(2);
      printf("The dice has landed on %d!\n\n", numDice);

      return numDice;
}

int play(int balance)
{
      int betVal = bet();

      int userVal = user_guess();

      int diceVal = dice_roll();

      sleep(1);

      if (userVal == diceVal) {
            balance = balance + betVal * 3;
            int profit = betVal * 3;

            printf("Congratulations, you were correct! You've earned %d€\n\n"
                  "Your balance is now %d€\n\n", profit, balance);
      }
      else {
            balance = balance - betVal;

            printf("Unfortunately, you lost money... Some %d€\n\n"
                  "Your balance is now %d€\n\n", betVal, balance);
      }

      while (balance > 0) {
            printf("Would you like to play again? (Y/N): ");
            fflush(stdout);
            char playAgain; scanf("%s", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y') {
                  balance = play(balance);

                  if (balance <= 0) {
                        bankruptcy();
                        return balance;
                  }
            }
            else if (playAgain == 'N' || playAgain == 'n') {
                  printf("\nUnderstood, exiting...\n");

                  sleep(1);

                  break;

                  return balance;
            }
            else {
                  printf("It's a yes or no question!\n");
            }
      }

      return balance;
}

int main()
{
      printf("★ Welcome to the Casino! ★\n");
      sleep(1);

      srand(getpid());


      printf("\nHere's how it works: you'll guess a number between 1 and 6 and we'll roll a dice.\n"
            "If it lands on the same number you guessed, you'll earn money, if not, you'll lose money.\n"
            "You can always exit and cash out whenever you want to.\n\n"
            "Your current balance is 1000€");
      sleep(6);

      int balanceMain = 1000; // Set the initial balance to 1000€
      play(balanceMain);

      return 0;
}
