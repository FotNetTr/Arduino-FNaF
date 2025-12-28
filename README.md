# Arduino FNAF-Style Game (Nokia 5110)

This project is a **Five Nights at Freddy’s–style survival game** developed using **Arduino** and a **Nokia 5110 (84x48) LCD**.  
The player must manage limited battery power while controlling doors and lights to survive against animatronics.

---

## Gameplay Overview

- The game starts with the battery at **100%**
- Battery drains automatically over time
- Closing doors increases battery consumption
- As the battery level decreases, more animatronics become active
- If a door is left open at the wrong time, a jumpscare occurs and the game ends
- If the battery reaches **0%**, a Freddy jumpscare is triggered
- If the player survives until the final stage, the game is won

---

## Controls

- **Left Light Button**: Checks the left hallway  
- **Right Light Button**: Checks the right hallway  
- **Left Door Button**: Opens / closes the left door  
- **Right Door Button**: Opens / closes the right door  

---

## Animatronics

- **Bonnie**: Attacks from the left side
- **Chica**: Attacks from the right side
- **Foxy**: Performs sudden attacks from the left
- **Freddy**: Attacks from the right in later stages

Animatronic behavior is tied to the battery level, increasing difficulty as the game progresses.

---

## Battery System

- Battery drains every game loop
- Additional drain occurs when doors are closed
- Battery level is displayed using **5 LEDs**
- When battery drops below **1%**, a jumpscare is automatically triggered

---

## Hardware Requirements

- Arduino Uno / Nano (compatible boards)
- Nokia 5110 LCD
- 4 push buttons
- 7 LEDs
- Resistors and jumper wires

---

## Technical Details

- Graphics are rendered as bitmaps on the LCD
- Game flow is controlled using `goto` labels
- Battery level functions as a **state-based progression system**
- Serial output is used for debugging and logging
