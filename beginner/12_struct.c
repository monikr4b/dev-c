/* struct.c */

#include <stdio.h>
#include <string.h> // Functions: strncpy

struct person {
      char title[8];
      char last_name[32];
      int age;
}; // End structs with a semicolon

int main()
{
      struct person Birch; // This is an *instanc* of the struct "person"

      strncpy(Birch.title, "doctor", 7); // Copies the first 7 characters of the string "doctor" into the struct "birch"'s member "title"
      strncpy(Birch.last_name, "Birch", 31);
      Birch.age = 38;

      printf("%s %s of age %d\n",
             Birch.title, // We use dots "." to access individual members of a struct like "structName.variable"
             Birch.last_name,
             Birch.age);

      return 0;
}