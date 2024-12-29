# Bits and char

When we create a large array of characters or of any object, it's good practice to make that array have a multiple of 64 bytes as its size. If something takes 4 bytes, e.g. `int`, divide 64 by 4 and make your length a multiple of that.

This is because a 64-bit CPU's cache lines are typically 64 bytes. Arrays that align with this size boundary reduce cache line spillover and maximize the utilization of each cache line. This can have big performance benefits that scale up with array sizes.