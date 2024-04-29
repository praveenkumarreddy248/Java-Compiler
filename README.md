
# Java Compiler

## Introduction

This is a multi-part Java compiler project. Each part focuses on implementing a specific component of the compiler, gradually building a complete compiler for the Java programming language.

## Part 1: Lexical Analysis with Lex

In the first part of the project, we implement the lexical analyzer using Lex. The lexical analyzer reads the input Java source code and tokenizes it into a sequence of tokens.

### Features

- Tokenizes Java source code into tokens such as identifiers, keywords, literals, and operators.
- Ignores comments and whitespace characters.

### Usage

1. Compile the Lex file:
   ```
   lex java.l
   cc lex.yy.c -o lexer -ll
   ```

2. Run the lexer on a Java source file:
   ```
   ./lexer <input-file>.java
   ```

## Part 2: Syntax Analysis with Lex and Bison

In the second part of the project, we enhance the compiler by adding a syntax analyzer using Lex and Bison. The syntax analyzer parses the token stream generated by the lexical analyzer and checks whether it conforms to the syntax rules of the Java language.

### Features

- Parses the token stream according to the Java grammar rules.
- Detects syntax errors and generates helpful error messages.

### Usage

1. Generate the parser using Bison:
   ```
   bison -d java.y
   ```

2. Compile the Lex and Bison files:
   ```
   lex java.l
   bison -d java.y
   gcc lex.yy.c java.tab.c -o parser -ll
   ```

3. Run the parser on a Java source file:
   ```
   ./parser <input-file>.java
   ```

## Part 3: Semantic Analysis with Lex and Bison

In the third part of the project, we implement the semantic analyzer using Lex and Bison. The semantic analyzer performs semantic checks on the parsed Abstract Syntax Tree (AST) to ensure that the program follows the semantic rules of the Java language.

### Features

- Checks for type compatibility, variable declarations, method calls, etc.
- Generates error messages for semantic violations.

### Usage


1. Generate the parser using Bison:
   ```
   bison -d java.y
   ```

2. Compile the Lex and Bison files:
   ```
   lex java.l
   bison -d java.y
   gcc lex.yy.c java.tab.c -o parser -ll
   ```

3. Run the parser on a Java source file:
   ```
   ./parser <input-file>.java
   ```

## Part 4: Intermediate Code Generation (ICG) with Lex and Bison

In the fourth part of the project, we implement the Intermediate Code Generator (ICG) using Lex and Bison. The ICG translates the validated AST into intermediate code, typically into a form like three-address code (TAC).

### Features

- Translates the AST into intermediate code representations.
- Prepares the code for optimization and target code generation.

### Usage


1. Generate the parser using Bison:
   ```
   bison -d java.y
   ```

2. Compile the Lex and Bison files:
   ```
   lex java.l
   bison -d java.y
   gcc lex.yy.c java.tab.c -o parser -ll
   ```

3. Run the parser on a Java source file:
   ```
   ./parser <input-file>.java
   ```

## Part 5: Optimization with Lex and Bison

In the final part of the project, we implement optimizations to improve the efficiency of the generated code using Lex and Bison. Optimization techniques may include constant folding, dead code elimination, and loop optimizations.

### Features

- Applies various optimization techniques to the intermediate code.
- Improves the performance and efficiency of the compiled code.

### Usage

*To be updated once implemented.*

## Contributing

Contributions are welcome! If you find any bugs or want to suggest improvements, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Special thanks to the authors of Lex and Bison for providing powerful tools for compiler construction.
- Inspired by the principles outlined in the "Dragon Book" (Compilers: Principles, Techniques, and Tools) by Aho, Lam, Sethi, and Ullman.

---