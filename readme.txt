Smart Calculator V1.5

A console-based smart calculator developed in C++ that supports advanced mathematical expression evaluation, percentage logic, and memory-based computation similar to real-world CASIO calculators. This project demonstrates strong fundamentals in programming logic, data structures, and problem-solving.

The calculator allows users to input full mathematical expressions such as "(20000 * 86)", handles operator precedence (BODMAS), and evaluates them using a stack-based parsing approach. It supports brackets, nested expressions, and multiple operations in a single line.

Key features include support for standard operators ("+ , - , * , / , % , ^"), power calculations, and decimal numbers (e.g. "1.222"). A custom percentage system is implemented to handle real-world use cases like "30% of 20000", "1000 * 30%`, and `50% + 20". Additionally, the calculator includes discount calculation functionality such as "20000 - 10% of 20000".

The program also features a memory system where the previous result can be reused using `y`, enabling continuous calculations. Additional controls include `r` for resetting the calculator and `q` for exiting the program. Output is formatted cleanly to avoid scientific notation, ensuring readability for large numbers.

Internally, the calculator uses stacks to manage values and operators, manually applying operator precedence and evaluating expressions step-by-step. This approach reflects how real interpreters and compilers process mathematical expressions.

Example expressions supported by the calculator include:
- 30% of 20000
- 1000 * 30%
- 50% + 20
- 20000 - 10% of 20000
- (10 + 5.5) * 2
- y + 10

A comprehensive test expression demonstrating multiple features: (20000 * 86) + 10% of 20000 - (5^2)


To run the project, download the source code, open it in any C++ IDE such as Dev-C++, Code::Blocks, or VS Code, compile the file, and execute the program in the console.

This project was built to strengthen understanding of control flow, expression parsing, and data structures in C++, while simulating the behavior of real-world calculators.

Author: Md. Robiul Islam 