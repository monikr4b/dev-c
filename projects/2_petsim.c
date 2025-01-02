/* Pet Simulator.c */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int balance = 1000;

int roulette(int max)
{
      unsigned int guess;
      int random;

      while (1)
      {
            printf("\nPick a number between 1 and 3, if you get it wrong, you'll lose 50€: ");
            scanf("%d", &guess);

            if (guess <= 0)
            {
                  printf("Your number isn't between 1 and 3. Try again...\n");
            }
            else { break; }
      }

      random = rand() % max + 1;

      if (guess == random)
      {
            balance += 1000;
      }
      else
      {
            balance -= 50;
      }

      return balance;
}

struct pet {
      char species[15];
      char name[20];
      int health;
      int hunger;
      int happiness;
};

int game(char g_species[15], char g_name[20])
{
      char answer, replay;
      int action, exit;

      exit = 1;

      struct pet MyPet;

      strncpy(MyPet.species, g_species, 14);
      strncpy(MyPet.name, g_name, 19);
      MyPet.health = 100; MyPet.hunger = 50; MyPet.happiness = 70;

      printf("\n\nYour %s's name is %s, its stats are:\n"
            "Health: %d\n" "Hunger: %d\n" "Happiness: %d\n\n",
            g_species, g_name, MyPet.health, MyPet.hunger, MyPet.happiness);
      usleep(1700000);

      printf("You can now choose to make your pet rest, to feed it or to play with them.\n\n"
            "To make them rest, enter '1'\n"
            "To feed them, enter '2' -> This costs 100€, your balance is %d\n"
            "To go play with them, enter '3'\n", balance);

      printf("\nI choose option ");
      scanf("%d", &action);

      switch (action)
      {
            case 1:
                  MyPet.health += 25;
                  MyPet.hunger -= 10;
                  printf("%s took a nap!\nHealth +25, Hunger -10\n\n", MyPet.name);
                  break;
            case 2:
                  MyPet.hunger -= 20;
                  MyPet.happiness += 20;
                  balance -= 100;
                  printf("You fed %s!\nHunger -20, Happiness +20\n\n", MyPet.name);
                  break;
            case 3:
                  MyPet.happiness += 25;
                  MyPet.health -= 20;
                  printf("You played with %s!\nHappiness +25, Health -20\n\n", MyPet.name);
                  break;
            default:
                  return exit;
      }

      while (1)
      {
            printf("Would you like to gamble for a chance at an extra 1000€? (Y/N): ");
            scanf("  %c", &answer);

            if (answer == 'y' || answer == 'Y')
            {
                  roulette(3);
                  break;
            }
            else if (answer == 'N' || answer == 'n')
            {
                  break;
            }
            else
            {
                  printf("It's a yes or no question!\n");
            }
      }

      printf("Your current balance is %d€\n\n", balance);

      do {
            printf("Would you like to play another turn? (Y/N) ");
            scanf(" %c", &replay);

            if (replay == 'y' || replay == 'Y')
            {
                  return 0;
            }
            else if (replay == 'n' || replay == 'N')
            {
                  return exit;
            }
            else if (replay != 'y' || replay != 'Y')
            {
                  printf("It's a yes or no question!\n");
            }
      }
      while (replay == 'n' || replay == 'N' || replay != 'y' || replay != 'Y');

      return 0;
}

int main()
{
      char species[15], name[20];
      int loop, pid, pid2;

      printf("❤︎ Welcome to MikuPets! ❤︎\n\n"
            "You can choose between a dog, a cat and an otter!\n\n");
      usleep(1900000);

      do {
            printf("Pick one: I want a pet... ");
            scanf("%s", species);

            if (!strcmp(species, "dog") || !strcmp(species, "cat") || !strcmp(species, "otter"))
            {
                  break;
            }
            else
            {
                  printf("\nYou didn't pick the right animal!, choose again.\n");
            }
      }
      while (strcmp(species, "dog") || strcmp(species, "cat") || strcmp(species, "otter"));

      printf("\nI want my pet to be called... ");
      scanf("%s", name);

      srand(getpid());

      for (int i = 0; i < 3; i++)
      {
            loop = game(species, name);

            if (loop == 1)
            {
                  printf("Exiting...");
                  sleep(1);
                  return 0;
            }

            if (i == 3)
            {
                  pid_t pid = fork();
            }
      }

      return 0;
}