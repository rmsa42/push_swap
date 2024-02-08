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
1. The `sort_three()` searches for the minimum number in stack `a`.
2. Then, the `sort_three()`, sees the position of the minimum number in stack `a`.
    - If the minimum number is in the `top` of stack `a`, the `top_min()` is called.
    - If the minimum number is in the `middle` of stack `a`, the `middle_min()` is called.
    - If the minimum number is in the `bottom` of stack `a`, the `last_min()` is called.
3. Now stack `a` will be sorted with operations like `sa`, `ra` and `rra`.

### Size 5
1. The `sort_five()` obtains the position of the minimum number, with `target()`, in stack `a`.
2. Then, `sort_five()`, moves the minimum number to the top of stack `a`.
3. Now, `sort_five()` does a `pb` operation, to push the minimum number to the top of stack `b`. 
4. Repeats `step 1, 2 and 3` until stack `a` has only 3 elemnts.
5. With only 3 elements, `sort_five()` calls `sort_three()`.
6. Now with stack `a` sorted, `sort_five()` does a `pa` operation to push the 2º minimum number (2º lowest off the five numbers) to the top of stack `a`.
7. Repeats `step 6`, to push the 1º minimum number (lowest of the 5 numbers) to the top of stack `a`.

### Size >5
1. The `sort_hundred()` is called and does two `pb` operations.
2. Then, `sort_hundred()` will do its algorithm until stack `a` has only 3 elemnts.
    - The `a_nbr2move()` calculates the best number to push to stack `b` and returns it (best number == least operations). To calculate the best number, the `mv_calcs()` will measure how many operations are needed to put the numbers from stack `a` into stack `b`, sorting them in descending order. The `mv_calcs()` is done in all numbers in stack `a`.
    - The `b_target()` calculates the number that has to be on the top of stack `b`, when pushing `a_nbr2move()` return value, and returns it.
    - The `sort()` will put the two numbers on the top of the respective stack and then it does a `pb`.
    - Repeat until stack `a` has only 3 elements.
3. With 3 elements in stack `a`, `sort_hundred` calls `sort_three()`.
4. Now, the `put_all_a()` is called, emptying stack `b` and filling stack `a`.
5. Then, rotating stack `a` will sort the stack.

Here's an example of how `sort_hundred()` works:
```bash
4                                                                                                                                                                                  3                 1
1                                                                                                                                                                   4              4                 2
7                7                                                                                                                            7                     5              5                 3
3      step 1    3      step 2    3     rrb, pb '3'          ra, pb '2'      2   step 3       2   step 4             pb     1      rra, pb    8     rra, rra, pb    6       pb     6      step 5     4
8     ------->   8     ------->   8     ---------->   8  3  ----------->     1  ------->      1  ------->   2  1  ------->  2     --------->  1     ------------->  7     ------>  7     --------->  5
2                2                2  7                2  1                5  7             5  7             5  7            5  7              2                     8              8                 6
5                5  1             5  4                5  7                6  4             6  4             6  4            6  4              5  4                  1              1                 7
6                6  4             6  1                6  4                8  3             8  3             8  3            8  3              6  3                  2  3           2                 8
_  _             _  _             _  _                _  _                _  _             _  _             _  _            _  _              _  _                  _  _           _  _              _  _
a  b             a  b             a  b                a  b                a  b             a  b             a  b            a  b              a  b                  a  b           a  b              a  b
```
In this example you can see the `mv_calcs()` calculations. In the first calculation, `mv_calcs()`, says that `3` is the best number. Why?. Ok, `mv_calcs()` starts calculating for the first number, in this case `3`, and the operations needed to put `3` in `b` are 2 (rra, pb). After this, `mv_calcs()` calculates for the second number, `8`, and says it needs 2 operations (ra, pb). Now, for the number `2` it needs 4 (ra, ra, rrb, pb). For the number `5` it needs 3 (rrr, rrr, pb). And for the `6` it needs 3 (rra, rb, pb).

Ok, but how can `mv_calcs()` knows what operations it has to do in order to put the numbers in `b`, sorting them in descending order?

First, `mv_calcs()` picks the first number in `a`, then goes through `b` finding the number that has to be in the top of `b` in order to be in descending order (this number is called `target`), and then it calculates the number of operations it has to do, to put that number in `b`.

So in the first case, the number `3`, its target would be the `highest number lower than 3` in `b`, in this case `1`. For the number `8` it would be the `7`, for `2` it is the `1`, for `5` and `6` it is `4`.

To this rule, theres only in one exception, the `lowest number`. If, in this example, we had a `0` in `a` its target would always be the highest number in `b`, in this case `7`. Why? Because, if you think about it, in ascending order the next number after the highest is the lowest, so in descending order is the inverse, the number before the highest needs to be the lowest. This is possible because thanks to the rotations operations.

After finding the target, `mv_calcs()` calculates the number of operations needed and the number with the least operations wins. Now the function `sort()` performs the operations.

In the `step 4`, the `put_all_a()`, has a similar system to target numbers in `a`. Its targets are the `lowest number higher than b_number`. So in the first case, the number `2`, its target would be the `5`. Then for the `1`, it is the `2`, for `7` it is `8`, for `4` it is `5` and for `3` it is `4`.

In `step 5` the stack is already sorted; it just needs to be rotated, so it is rotated until the lowest number (`1`) is on top.

## Bonus
For the bonus part, in this project we need to do a `checker` that reads all the operations `push_swap` prints and sees if the stack, with that set of operations, finishes sorted.

The `checker` initializes stack `a`, equal to the `push_swap`.
It needs an operation reader, `get_next_line(0)` will be the reader.

Now it needs to make the operations that `get_next_line(0)` reads and after the last operation it needs to check if `a` is sorted. If it is, prints `OK`, otherwise `KO`.

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
