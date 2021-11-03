# Push Swap

The program generate the shortest set of push_swap instructions to sort a stack
of numbers. \

## Table of contents

 - [Introduction](#introduction)
 - [What are push_swap instructions](#what-are-push_swap-instructions)
 - [Usage of push_Swap](#usage-of-push_swap)
 -- [Compiling](#compiling)
 -- [Using push_swap to sort a stack](#using-push_swap-to-sort-a-stack)

## Introduction

push_swap uses two stacks: a and b. In the a stack will init with the values
passed as arguments, the b stack will auxiliate in the sort process.

## What are push_swap instructions

The push_swap instructions are: \
 - sa : swap the top 2 itens on stack a. \
 - sb : swap the top 2 itens on stack b. \
 - ss : execute sa and sb at the same time. \
 - pa : push the top iten on stack a to the top of stack b. \
 - pb : push the top iten on stack b to the top of stack a. \
 - ra : shift up all the itens on stack a, the first iten goes to the bottom of 
the stack. \
 - rb : shift up all the itens on stack b, the first iten goes to the bottom of
the stacK. \
 - rr : execute ra and rb at the same time. \
 - rra : shift down all the itens on stack a, the last iten goes to the top of
the stack. \
 - rrb : shift down all the itens on stack b, the last iten goes to the top of
the stack. \
 - rrr : execute rra and rrb at the same time.

## Usage of push_swap

### Compiling

Call make to compile the program. Requires clang-13. \
The Makefile also provide the rules "clean", "fclean" and "re". "clean" will
erase the *.o files, "fclean" will completly erase the program (but preserve the
source code), "re" will execute "fclean" then "all" the recompile the program.

### Using push_swap to sort a stack

After compiling call "./push_swap <int> <int> ...", it will test the complexity
of the problem and then will generate a query of [push_swap instructions](#what-are-push_swap-instructions)
(described above), or send a error message. \
An error message will appear if: The problem is too complex and can't be solved;
you had passed a invalid argument (a alphabetic character).
