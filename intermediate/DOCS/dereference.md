# Dereferencing Pointers

## TL;DR

There is a difference between using and not using `*` when referring to a pointer in C code:
- Using `*` means we are **dereferencing** the pointer: accessing the value at the memory location the pointer points to.
- Not using `*` means we're altering the value with the pointer holds--a memory address.
<br></br>

In C we have two different ways to assign a value to a pointer. This is because there pointers relate to two values:
- The **memory address** they point to
- The **value stored** *at* that memory address

Even though a pointer is *related* to two values, it only stores the **memory address** itself. The value inside that memory address is held in memory and isn't assigned to a variable unless we make it so.

To exemplify this, we can take the code for [ampersand.c](/intermediate/1_ampersand.c).

**EXAMPLE 1**:
```c
void addition(int *target, int x, int y)
{
      *target = x + y;
}
```
In this example, we define a pointer `*target` to an integer in the function's parameters.
We then make `*target` equal to x + y.

**EXAMPLE 2**:
```c
void addition(int *target, int x, int y)
{
      target = x + y;
}
```
In this example, we do the same thing except we make `target` (without the star) equal to x + y.
<br></br>

The difference between these two statements is the dereference operator `*` being present before `target` in the first example and not in the second.

In example 1, by making `*target` equal to x + y, we are making the **value stored** at the memory address the pointer points to equal to x + y.

In example 2, we instead make `target` (without the star) equal to x + y, This makes the **memory address** stored in the pointer equal to x + y.
Since x + y has type `int` and a memory address looks something like `0x12345678`, this is an invalid operation and won't even compile.
