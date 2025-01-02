/* dicegame.c */

#include <stdio.h>   // Funbctions: printf(); scanf(); fflush();
#include <unistd.h>  // Functions: (u)sleep(); getpid();
#include <stdlib.h>  // Functions: srand(); rand();

int dice_roll(int max)
{
      int diceNum = rand() % max + 1; /* The number the dice will land on is equal to the remainder of the division of a (pseudo-)random value of arbitrary
                                      size and the maximum value + 1; this means it'll be a number between 1 and max */

      return diceNum;
}

int main()
{
      int balance, bet, guess, dice;

      srand(getpid()); /* The seed for our "random" number is the process ID of the dice game executable, which changes at every execution
                       (but remains constant throughout a single runtime) */

      balance = 1000;

      printf("★ Welcome to the Casino! ★\n");
      sleep(1);

      printf("\nHere's how it works: you'll guess a number between 1 and 6 and we'll roll a dice.\n"
            "If it lands on the same number you guessed, you'll earn 3x your bet, if not, you'll lose your bet.\n"
            "You can always exit and cash out whenever you want to.\n\n"
            "Your current balance is 1000€\n\n");
      usleep(3200000); // usleep() is the same as sleep() except it takes in an whole value of microseconds instead of seconds
                       // This is necessary to enter fractional amounts of seconds, because sleep() functions only accept integers as args

      while (1 == 1) // A while loop with a condition that always evaluates to true keeps the code within the brackets in an infinite loop of execution
      {
            printf("Enter your betting amount (€): ");
            scanf("%d", &bet); // The user is asked to enter his betting amount, which is passed to the bet variable

            printf("\nGuess the number the dice will land on (between 1-6).\nIf you wish to quit the game, enter 0.\n\n");

            sleep(2);

            printf("I think the dice will land on ");
            scanf("%d", &guess);

            while (guess > 6 || guess < 0) { // The submitted value must be between 6 and 1, if not, the user will stay in a loop
                  printf("Your number isn't between 1 and 6, re-enter it: ");

                  scanf("%d", &guess);
            }

            if (guess == 0) {
                  return 0; // Exits the program by returning 0 (the value that corresponds to successful execution)
            }

            printf("\nThrowing the dice...\n");

            dice = dice_roll(6); // Rolls the dice with maximum value of 6

            sleep(2);
            printf("The dice has landed on %d!\n\n", dice);
            sleep(1);

            if (guess == dice)
            {
                  balance = balance + (bet * 3);
                  int profit = bet * 3;

                  // If the user guessed correctly, award them with their bet's value times three and add it to their balance

                  printf("Congratulations, you've earned %d€\n"
                        "Your current balance is %d€\n\n", profit, balance);
            }
            else
            {
                  balance = balance - bet;

                  // If not, subtract the bet's value from the balance

                  printf("Unfortunately, you lost %d€\n"
                        "Your current balance is %d€\n\n", bet, balance);
            }

            if (balance == 0)
            {
                  printf("You're all out of cash. You're a failure!\n");
		      return 0; // Declare bankruptcy and exit the program
            }

            sleep(2);

            while (balance > 0) { // If the user isn't bankrupt, ask them if they'd like to play again

                  printf("Would you like to play again? (Y/N): ");

                  char playAgain; scanf("%s", &playAgain);

                  if (playAgain == 'Y' || playAgain == 'y') // Adds support for both uppercase and lowercase answers
                  {
                        printf("\n");
                        break; // "Breaks" out of the play again question loop and back into the gameplay loop, where the user wil get to play again
                               // This allows the user to keep playing forever if they wish to do so
                  }
                  else if (playAgain == 'N' || playAgain == 'n')
                  {
                        printf("\nExiting...\n");
                        sleep(1);

                        return 0;
                  }
                  else {
                        printf("It's a yes or no question!\n"); // Forces the user to reply with Y or N
                  }
            }
      }
}
