# Compiler Design Lab - Experiments 1 to 20

These C programs are prepared for GCC in VS Code. Each experiment is a separate `.c` file.

## Compile and run (Windows PowerShell)

Open the terminal in this folder. For example, to run Experiment 1:

```powershell
gcc Exp01_Lexical_Analyzer.c -o exp01.exe
./exp01.exe
```

Use the matching filename for each experiment. You can also compile with:

```powershell
gcc filename.c -o program.exe
./program.exe
```

## Input notes

- Exp01: Enter a C expression, e.g. `a = b + c * 100`.
- Exp02: Enter a comment, e.g. `// this is a comment` or `/* comment */`.
- Exp03: Enter C code on multiple lines; type `END` on its own line to finish.
- Exp04: Enter one arithmetic operator: `+`, `-`, `*`, or `/`.
- Exp05: Enter text, then press Ctrl+Z and Enter to finish input in Windows PowerShell.
- Exp06: Enter an identifier, e.g. `total_1`.
- Exp07: Enter productions without spaces, e.g. `S=AB`, `A=a`, `B=$`, then query `S`. `$` represents epsilon.
- Exp08: Enter productions in the same format, then query a non-terminal. This implementation supports the simple grammar format used in the lab.
- Exp09: Enter one production, e.g. `L->L,S|S`.
- Exp10: Enter one production, e.g. `S->iEtS|iEtSeS|a`.
- Exp11: Use menu choices to insert, display, search and modify symbols.
- Exp12: Enter an expression such as `(a+b)*c`. Grammar supports identifiers, `+`, `*`, and parentheses.
- Exp13: Enter a string such as `aabbb`. Grammar is `S -> aS | Sb | ab`.
- Exp14: Enter an expression with single-letter identifiers, e.g. `a+b`.
- Exp15: Enter an arithmetic expression such as `a*(b+c)`.
- Exp16: Enter an assignment such as `out=in1+in2+in3-in4`.
- Exp17: Enter `sample_input.txt` to count the included sample file, or enter another text filename.
- Exp18: Enter a number of three-address statements, then statements such as `a=b+c`.
- Exp19: Prints LEADING sets for the grammar specified in the program.
- Exp20: Prints TRAILING sets for the grammar specified in the program.

## Included sample files

- `sample_input.txt` is used by Experiment 17.
- `sample_input.c` is an example source file.

## Notes

- Programs use standard C and are intended to compile with GCC.
- Exp19 and Exp20 print the sets for the exact grammar shown in those programs.
- Exp08 is a simple FIRST/FOLLOW implementation for the lab-style grammar format, not a full general-purpose grammar toolkit.
