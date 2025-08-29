# C++ Learning Mini Projects

A personal sandbox of small C++ console programs I’m writing to practice and solidify the fundamentals of the language.  
I publish everything (including naive / first attempts) so:
- You can follow my progression over time (early → refactored versions).
- You are free to reuse, improve, or treat the code as an exercise “solution idea”.
- Ideas here can serve as starters for your own practice.

> Learning Goal: Build many tiny, self‑contained programs; focus on clarity first, then iterate with incremental refinements (structure, error handling, tests, performance).

---

## Why This Repository Exists

Instead of one “perfect” example, I prefer:
- Frequent commits that capture the learning journey.
- Readable, explicit code over clever one‑liners.
- Gradual introduction of abstractions (only when a pattern repeats).
- Annotated TODOs to signal what I intend to revisit later.

If you’re also learning: clone a project, delete parts, and try re‑implementing them yourself—then compare approaches.

---

## Table of Contents
1. Overview
2. Learning Principles
3. Build & Run
4. Projects
   - Calculator
   - Convertissor (Unit Converter)
   - Guess Number
5. Reuse & Contribution
6. Conventions & Style
7. Roadmap (Personal & Stretch)
8. Progress Log (Snapshots)
9. License
10. Quick Reference

---

## 1. Overview

| Project        | Purpose                                        | Concepts Practiced                               |
|----------------|------------------------------------------------|--------------------------------------------------|
| Calculator     | Multiple arithmetic ops via CLI flags          | Argument parsing, arithmetic, output formatting  |
| Convertissor   | Simple metric unit conversions                 | Control flow, numeric scaling, validation        |
| Guess Number   | Number guessing game with random target        | Loops, conditionals, RNG (`<random>`), I/O       |

Planned (exploratory ideas): time converter, file stats, sorting demo, temperature converter, prime utilities, simple text parser, small allocator experiment.

---

## 2. Learning Principles

I try to:
1. Start with the most direct, readable implementation (no premature templating).
2. Only refactor when duplication or friction appears.
3. Prefer standard library facilities over reinventing (but occasionally reinvent to learn).
4. Add error handling progressively (not all early commits have robust checks).
5. Leave breadcrumbs (comments / TODO) so future me can revisit intent.

Labels you may see:
- TODO: Intention to improve later.
- NOTE: Design decision explanation.
- EXPERIMENT: Code left in a draft / exploratory state.

---

## 3. Build & Run

### Prerequisites
- A C++17 (or later) compiler: g++, clang++, or MSVC
- (Optional) CMake ≥ 3.15 for a unified build system

### A. Direct Compilation (if each project is a single .cpp)
```bash
# Linux / macOS
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o calculator src/calculator.cpp
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o convertissor src/convertissor.cpp
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o guess_nbr src/guess_number.cpp
```

```powershell
# Windows (PowerShell) with MinGW
g++ -std=c++17 -O2 -Wall -Wextra -pedantic -o calculator.exe src\calculator.cpp
```

### B. Suggested CMake Layout
```
.
├── CMakeLists.txt
├── calculator/
│   ├── CMakeLists.txt
│   └── calculator.cpp
├── convertissor/
│   ├── CMakeLists.txt
│   └── convertissor.cpp
└── guess_number/
    ├── CMakeLists.txt
    └── guess_number.cpp
```

Top-level CMake example:
```cmake
cmake_minimum_required(VERSION 3.15)
project(LearningMiniProjects CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
add_subdirectory(calculator)
add_subdirectory(convertissor)
add_subdirectory(guess_number)
```

Per subdirectory:
```cmake
add_executable(calculator calculator.cpp)
target_compile_options(calculator PRIVATE -Wall -Wextra -Wpedantic)
```

Build:
```bash
cmake -S . -B build
cmake --build build --config Release
```

---

## 4. Projects

### 4.1 Calculator
Chained arithmetic operations in a single command.

Example:
```
.\calculator.exe --add 2 2 --sous 2 3 --mult 5 5 --div 9 3 --pow 3 2 --mod 2 2
```
Output:
```
4 -1 25 3 9 0
```

Flags (current naming; some bilingual):
- --add A B   : A + B
- --sous A B  : A - B (FR “soustraction”) — will likely rename to --sub
- --mult A B  : A * B
- --div A B   : A / B
- --pow A B   : A ^ B (exponent)
- --mod A B   : A % B
- --help      : Usage

Improvement Targets:
- Input validation (overflow? division by zero).
- Optional labelled output (e.g. `add=4 sub=-1 ...`).
- Support chained expressions or parentheses in a future version.

### 4.2 Convertissor (Unit Converter)
Converts between simple metric units.

Example:
```
.\convertissor.exe convert 10 m cm
```
Output (current):
```
1000cm
```
Planned Enhancements:
- Space formatting: `1000 cm`
- Bidirectional unit map: km ⇄ m ⇄ cm ⇄ mm
- Add alias “converter” binary or fallback
- Support categories (length, mass, volume) with errors on cross-category conversion

### 4.3 Guess Number
Interactive console guessing game.

Example:
```
.\guess_nbr.exe --limit 10
```

Current (French) sample:
```
-----------| Deviner le nombre |-----------
--> 5
Plus petit
--> 2
Plus grand
--> 3
Trouvé ! Bien joué
```

Planned English mode:
```
-----------| Guess the Number |-----------
> 5
Lower
> 2
Higher
> 3
Found it! Well done.
```

Possible Future Options:
- --attempts N (limit guesses)
- Difficulty presets: easy / normal / hard
- Track stats across runs (session only)

---

## 5. Reuse & Contribution

You are free to:
- Copy code into your own exercises.
- Fork and experiment (submit PRs if you think something improves learning clarity).
- Create alternative implementations (e.g. templated version vs plain).

If you reuse code publicly:
- A small attribution link is appreciated but not required.

PR Style (if contributing):
1. Keep changes focused (one project / concept).
2. Explain the learning value of the change:
   - “Refactor: replaced manual loop with std::accumulate to illustrate algorithm usage.”
3. Avoid large frameworks; minimal standard library first.

---

## 6. Conventions & Style

Current Status vs Goals:

| Aspect              | Current State                                 | Target Direction                                      |
|---------------------|-----------------------------------------------|-------------------------------------------------------|
| Language            | Mixed FR/EN flags / messages                  | Toggle locale or standardize to EN                    |
| Error Handling      | Basic or missing in earliest versions         | Consistent stderr + exit codes                        |
| CLI Parsing         | Manual argv scanning                          | Possibly small utility wrapper (no heavy deps)        |
| Build System        | Manual + optional CMake                       | Unified CMake, maybe presets                          |
| Testing             | None yet                                      | Introduce Catch2 / doctest gradually                  |
| Output Formatting   | Minimal tokens                                | Optional verbose / JSON modes                         |
| Documentation       | Expanding README only                         | Add per-project README or inline comments             |

Coding Flags Suggestion:
```
-Wall -Wextra -Wpedantic -Wconversion -Wshadow
```

---

## 7. Roadmap (Personal & Stretch)

Short Term:
- [ ] Rename FR flags (`--sous`) to English with backward compatibility
- [ ] Add basic input validation & friendly error messages
- [ ] Implement unit map for Convertissor
- [ ] Add attempt counter to Guess Number

Medium:
- [ ] Introduce minimal test harness (Catch2 or doctest)
- [ ] Add locale switch (`--lang en|fr`)
- [ ] Colorize terminal output (optional flag)
- [ ] Shared CLI parsing helper header

Stretch:
- [ ] GitHub Actions CI (matrix: Ubuntu / Windows / macOS)
- [ ] Additional projects (sorting demo, file stats, primes)
- [ ] Release tagged educational checkpoints (v0.1, v0.2 ...)
- [ ] Benchmark simple optimizations (e.g., micro timing utilities)

---

## 8. Progress Log (Snapshots)

| Date (Approx) | Change / Focus                                  | Notes |
|---------------|--------------------------------------------------|-------|
| 2025-01 Early | Initial Calculator, raw parsing                  | Direct argv handling |
| 2025-01 Mid   | Add Convertissor prototype                       | Simple string comparisons |
| 2025-02       | Guess Number added (FR output)                   | Introduced `<random>` |
| Planned       | Refactor flags to consistent English             | Backward compatibility with alias map |

(Will expand this table as I commit more iterations.)

---

## 9. License

I intend to keep this permissive. Unless changed later:
```
MIT License © 2025 matth-blt
```
(If there is no LICENSE file yet, treat it as “intended MIT”; I will add the file.)

---

## 10. Quick Reference

| Executable    | Example Usage                                 |
|---------------|-----------------------------------------------|
| calculator    | `./calculator --add 2 2 --pow 3 3`            |
| convertissor  | `./convertissor convert 10 m cm`              |
| guess_nbr     | `./guess_nbr --limit 50`                      |

---

## How You Can Use This Repo

- As a baseline: try rewriting one tool before reading my version.
- As a diff study: when I refactor, compare old vs new for reasoning.
- As a template: adapt the CMake layout for your own practice set.

If you’d like a dedicated branch that shows “before” vs “after” for a refactor, open an issue and I can curate that.

---

Thanks for stopping by.  
Feedback or ideas welcome—especially suggestions that improve the learning clarity rather than just “making it fancier”.

Happy coding & steady progress 🚀
