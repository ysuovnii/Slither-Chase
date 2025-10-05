# Slither Chase

#  Overview
**Slither Chase** is a **local multiplayer console game** written in **C++**.  
One player controls the **Snake**, and the other controls the **Rat**.  
The Snake’s mission: **catch the Rat**.  
The Rat’s mission: **survive and escape!**

##  Game Concept
- A 2-player **competitive survival** game running entirely in the console.  
- Uses **ANSI color codes** for a colorful terminal display.  
- Features **real-time input handling** for both players using the keyboard.

##  How to Play

###  Controls

| Player | Character | Controls |
|:-------:|:----------|:----------|
| Player 1 | 🐍 Snake | `W` = Up, `S` = Down, `A` = Left, `D` = Right |
| Player 2 | 🐭 Rat | Arrow Keys ↑ ↓ ← → |



###  Objective
- **Snake:** Catch the Rat before it escapes.  
- **Rat:** Keep dodging and surviving as long as possible.  



###  Powerups
- Eating a **Fruit (F)** grants the Snake **temporary wall-crossing powers**, allowing it to chase the Rat beyond the arena boundaries.  
- The effect lasts for a **short duration**, so time your moves wisely!



##  Features
- Local multiplayer gameplay  
- Real-time movement using keyboard input  
- Color-coded Snake, Rat, and Fruit using ANSI escape sequences  
- Dynamic arena and chase mechanics  
- Simple yet fun gameplay loop  



##  Tech Stack
- **Language:** C++  
- **Libraries Used:**
  - `<iostream>` — Input/Output
  - `<conio.h>` — Keyboard input
  - `<windows.h>` — Screen clearing and delay
  - `<ctime>` / `<cstdlib>` — Random fruit spawning




