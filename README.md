```markdown
# DialogueEngine

A simple, data-driven dialogue tree engine written in C++. Designed to read, parse, and execute branching narrative structures dynamically from external text files.

## How It Works

The execution process runs in three main steps:

1. **Parser:** Scans the raw `story.txt` script and converts custom syntax tags (`NODE:`, `TEXT:`, `OPTION:`) into structured C++ data objects.
2. **State Machine:** Maps parsed dialogue nodes into memory (`std::map`) and manages narrative state transitions based on player choices.
3. **Input Sanitizer:** Handles console input validation (`std::cin.clear()`, `std::cin.ignore()`) to prevent crash loops and invalid state transitions.

## Features

* **Data-Driven Architecture:** Story content is completely decoupled from execution logic, allowing script edits without recompiling.
* **Stream Safety:** Protected against non-integer user inputs and invalid choice indices.
* **Zero Dependencies:** Built entirely using standard C++ STL components (`std::map`, `std::vector`, `std::ifstream`).

## Project Structure

* `main.cpp` : Core engine logic, file parsing, input sanitization, and main game loop.
* `story.txt` : External narrative script defining node IDs, dialogue text, and branching options.
* `.gitignore` : Configuration file to exclude build artifacts and executable files.

## How to Run

Requires a C++11 (or higher) compliant compiler. No third-party libraries are needed.

1. Compile the C++ source file:
   ```bash
   g++ main.cpp -o DialogueEngine

```

2. Run the compiled executable:
```bash
./DialogueEngine

```


## Author

**Orkun Aydın Alper**
Computer Engineering, Ankara Science University

```
