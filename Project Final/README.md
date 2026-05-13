# COP3223 Calculator Project (Paper Tape Calculator)

## Overview
This project is a command-line scientific calculator implemented in C.  
It supports binary and unary operations, memory functions, and a "paper tape" output system that logs results to a file.

The calculator continuously prompts the user for input until the quit command is entered.

---

## Features

### Basic Arithmetic (Binary)
- Addition: `+`
- Subtraction: `-`
- Multiplication: `x`
- Division: `/`
- Exponentiation: `^`

### Scientific Functions (Unary)
- `sin`, `cos`, `tan`
- `asin`, `acos`, `atan`
- `sqrt` (square root)
- `abs` (absolute value)
- `inv` (reciprocal: 1/x)
- `log10` (base 10 logarithm)
- `log2` (base 2 logarithm)

### Constants
- `pi` → π (3.14159...)
- `e` → Euler’s number (2.71828...)

---

## Special Features

### History Navigation (`b`)
- Allows the user to go back through previous results.
- Users can repeatedly press `b` to step backwards through stored values.
- Pressing ENTER selects the current displayed value.

---

### Paper Tape Output
- All results are written to:
