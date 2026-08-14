# Dialogue Engine

This repository contains C++ source files, narrative script definitions, and build configurations for the Dialogue Engine project.

## Project Structure
- main.cpp: Core engine logic, file parsing, input sanitization, and main execution loop.
- story.txt: External narrative script defining node IDs, dialogue text, and branching options.
- .gitignore: Configuration file to exclude build artifacts and executables.

## Requirements & Setup
- C++11 (or higher) compliant compiler (`g++`, `clang++`, or MSVC)
- Standard C++ Library (`iostream`, `fstream`, `vector`, `map`)

## How to Run
Compile and execute the program via terminal:

```bash
g++ main.cpp -o DialogueEngine
./DialogueEngine
