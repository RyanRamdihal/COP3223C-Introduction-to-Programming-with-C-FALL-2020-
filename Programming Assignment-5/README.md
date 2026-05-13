# Program Assignment 5 - Dynamic Memory Allocation (Structures)

## Overview
This program reads slope-intercept data and a list of x-values from an input file, dynamically allocates memory for a structure and its arrays, computes corresponding y-values, and writes the results to an output file.

The assignment focuses on proper use of:
- Dynamic memory allocation
- Structs
- Pointers
- Constructor and destructor functions
- File input/output

---

## Assignment Description
This program was designed to practice dynamic memory allocation in C.

It requires the program to:
- Open an input file (`as5input.txt`) for reading
- Open an output file (`as5output-lastname-firstname.txt`) for writing
- Store data inside a dynamically allocated structure
- Allocate memory for arrays at runtime
- Compute y-values using slope-intercept form
- Properly free all allocated memory using a destructor function

---

## Data Structure

The program uses a struct containing:

- `float m` → slope  
- `float b` → y-intercept  
- `int count` → number of x-values  
- `double *x` → dynamically allocated array of x-values  
- `double *y` → dynamically allocated array of computed y-values  

---

## Input Format
The input file (`as5input.txt`) contains:

- A slope and intercept value (on one line)
- An integer count
- A list of `count` x-values

---

## Computation
The program computes y-values

For each x-value:
- Compute corresponding y-value
- Store results in dynamically allocated arrays inside the struct

---

## Memory Management
The program includes:
- **Constructor function**
  - Allocates memory for struct, x array, and y array

- **Destructor function**
  - Frees x array
  - Frees y array
  - Frees struct itself

---

## Output Format
The output file includes:
- Slope (m)
- Y-intercept (b)
- Each x-value paired with its computed y-value

---

## Features
- Dynamic memory allocation using `malloc`
- Struct-based data organization
- Constructor/destructor pattern
- File reading and writing
- Mathematical computation using arrays

---

## Technologies Used
- C Programming Language
- Standard Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `math.h`
  - `string.h`

---

## Skills Demonstrated
- Pointers and dynamic memory
- Struct design
- Memory management best practices
- File I/O handling
- Function-based program structure

---

## Notes
This program must compile without warnings and correctly handle valid input files. All dynamically allocated memory must be properly freed before program termination.
