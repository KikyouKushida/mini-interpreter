# Mini Interpreter in C++

A small interpreted language with expression parsing, statement execution, and program-level parsing, designed for extensibility.

## Features
- Tokenizer
- Recursive descent parser
- AST construction
- Operator precedence and parentheses

## Example

1 + 2 * (3 + 4)
 => (+ 1 (* 2 (+ 3 4)))

Support: (As an entire program)

a = 3

b = (a * a) + (a + 5) + 2 * 3

print(b)

