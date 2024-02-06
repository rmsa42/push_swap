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


## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
