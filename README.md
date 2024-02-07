# Push_Swap [42 Project]
This 42 project challenges us to create a sorting algorithm, with a predefined set of operations, to sort a stack of integers.

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Dependencies](#dependencies)
4. [How to Use](#how-to-use)
5. [Code Example](#code-example)
6. [Algorithm](#algorithm)
7. [Bonus](#bonus)
8. [Contributing](#contributing)

## Overview
The goal of this project is to sort data on a stack using the lowest possible number of operations.

### The Rules
- You have 2 stacks named `a` and `b`
- At the beggining:
  - The stack `a` contains a random amout of positve and/or negative numbers, which cannot be duplicated
  - The stack `b` is empty
- The goal is to sort in ascending order numbers into stack `a`. To do so you have the following operations:
  - `sa`: Swap the first 2 elements of `a`
  - `sb`: Swap the first 2 elements of `b`
  - `ss`: Do `sa` and `sb` at the same time
  - `pa`: Push the first element of `b` and put it at the top of `a`
  - `pb`: Push the first element of `a` and put it at the top of `b`
  - `ra`: Rotate up all elements of `a` by 1 (The first element becomes the last)
  - `rb`: Rotate up all elements of `b` by 1 (The first element becomes the last)
  - `rr`: Do `ra` and `rb` at the same time
  - `rra`: Rotate down all elements of `a` by 1 (The last element becomes the first)
  - `rrb`: Rotate down all elements of `b` by 1 (The last element becomes the first)
  -  `rrr`: Do `rra` and `rrb` at the same time

Doing any operation counts as 1 operation done. So if i do `sa`, `pa` and `ss`, it counts as 3 operations done.

Here's an example of the sorting process with 7 operations:
```bash
1                                                                                 7              1
4               4               7                                                 1              2
7       pb      7       sa      4       pb      4       rr      2      pa, pa     2      ra      3
2     ------>   2     ------>   2     ------>   2  7  ------>   3  1  -------->   3    ------>   4
3               3  1            3  1            3  1            4  7              4              7
_  _            _  _            _  _            _  _            _  _              _  _           _  _
a  b            a  b            a  b            a  b            a  b              a  b           a  b
```

## Project Structure
- `push_swap/`: Main directory containing all the directories and files:
  - `src/`: Contains all the source code
  - `src_bonus/`: Contains all the source code for the bonus part
  - `libft/`: Contains the libft library
  - `include/`: Contains the header file
  - `Makefile`: Build automation file

Inside the `src/` the files are organized as follows:

- `push_swap`: Main file
- `movements`: Contains all the operations
- `sort_three`: Contains the 3 number sort algorithm
- `sort_five`: Contains the 5 number sort algorithm
- `sort_big`: Contains the >5 number sort algorithm (execution)
- `strat`: Contains the >5 number sort algorithm (calculation)
- `checks_erros`: Contains the error handling part
- `list_utils`: Contains all utility to manipulate the stack

## Dependencies
- Libft (aleready included).

## How to Use
1. Clone the repository.
2. Navigate to the `push_swap` directory: `cd push_swap`.
3. Compile the program: `make`.
4. Run the `push_swap` binary: `./push_swap stack_random_numbers`.

## Code Example
Example: push_swap sorting a stack of 5 numbers:
```bash
./push_swap 10 23 7 2 9
rra
rra
pb
rra
pb
```

## Algorithm
Here's an explanation about the algorithm that used in my push_swap.

### Size 2
If the stack is sorted, it does nothing.

If the stack is not sorted, a simple `sa` sorts the stack.

### Size 3
1. The `sort_three()` searchs for the minimum number in the stack `a`.
2. Then, the `sort_three()`, sees the position of the minimum number in the stack `a`.
    - If the minimum number is in the `top` of the stack `a`, the `top_min()` is called.
    - If the minimun number is in the `middle` of the stack `a`, the `middle_min()` is called.
    - If the minum number is in the `bottom` of the stack `a`, the `last_min()` is called.
3. Now the stack `a` will be sorted with operations like `sa`, `ra` and `rra`.

### Size 5
1. The `sort_five()` obtains the position of the minimum number, with `target()`, in the stack `a`.
2. Then, `sort_five()`, moves the minimum number to the top of the stack `a`.
3. Now, `sort_five()` does a `pb` operation, to push the minimum number to the top of the stack `b`. 
4. Repeats `step 1, 2 and 3` until the stack `a` has only 3 elemnts.
5. With only 3 elements, `sort_five()` calls `sort_three()`.
6. Now with the stack `a` sorted, `sort_five()` does a `pa` operation, to push the 2º minimum number (2º lowest off the five numbers) to the top of the stack `a`.
7. Repeats `step 6`, to push the 1º minimum number (lowest of the 5 numbers) to the top of the stack `a`.

### Size >5
1. The `sort_hundred()` is called, and does two `pb` operations.
2. Then, `sort_hundred()` will do its algorithm until the stack the `a` has only 3 elemnts.
    - The `a_nbr2move()` calculates the best number to push to the stack `b` and returns it. (best number == least operations). To calculate the best number, the `mv_calcs()` will measure how many operations are needed to put the number of the stack `a` in the stack `b`, sorting it descending. The `mv_calcs()` is done in all numbers in stack `a`.
    - The `b_target()` calculates the number that has to be on the top of the stack `b`, when pushing `a_nbr2move()` return value, and returns it.
    - The `sort()` will put the two numbers on the top of the respective stack and then it does a `pb`.
    - Repeat until stack `a` has only 3 elements.
3. With 3 elements in stack `a`, it calls `sort_three()`.
4. Now, the `put_all_a()` is called, emptying stack `b` and filling stack `a`.
5. Then rotating stack `a` will sort the stack.

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
