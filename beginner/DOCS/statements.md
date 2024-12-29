
# Conditional Statements in C

## "while"

***While*** a specified condition is true, execute the code inside the brackets:

```c
while (2 + 2 == 4) {
        printf("This'll repeat forever...");
}
```

## "if"

***If*** a specified condition is true, execute the code inside the brackets:

```c
int x;
scanf("%d", &x);

if (x > 100) {
    printf("The value of x is above 100");
}
```

## "else if"

If the first "if" statement's condition is false but this new condition is true, executes the code in brackets

```c
if (grade == 100) {
    printf("You got every question right!");
}

else if (grade > 50) {
    printf("You didn't get every question right, but you still passed.");
}
```

## "else"

If all previous "if" and "else if" statements' conditions were false, executes the code in brackets

```c
if (grade == 100) {
    printf("You got every question right!");
}

else if (grade > 50) {
    printf("You didn't get every question right, but you still passed.");
}

else {
    printf("I'm sorry, but you failed the test...");
}
```