# How to Run `Slither Chase.cpp`

This guide explains how to compile and run the `Slither Chase.cpp` game file on your system.

---

## 🪟 Windows

1. Make sure you have **g++** installed (via MinGW or similar).
2. Place the `Slither Chase.cpp` file in a folder.
3. Open **Command Prompt** in that folder.
4. Compile the code:

   ```bash
   g++ "Slither Chase.cpp" -o SlitherChase
   ```
5. Run the game:

   ```bash
   SlitherChase
   ```

## 🐧 Linux / macOS

> Note: Current code uses `<conio.h>` and `<windows.h>`, which are Windows-only.
> To run on Linux/macOS, you'll need to modify the code to use `ncurses` or another cross-platform library.

1. Install `g++` if not already installed.
2. Open terminal in the folder containing `Slither Chase.cpp`.
3. Compile the code (Windows code may not run directly on Linux/macOS):

   ```bash
   g++ "Slither Chase.cpp" -o SlitherChase
   ```
4. Run the game:

   ```bash
   ./SlitherChase
   ```
