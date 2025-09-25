Parfait 👍 je vais refaire le **README en anglais complet** avec toutes les parties (base, improved version, AND the feature with custom labyrinths from text files).
Ça donnera un rendu professionnel pour GitHub 👌

Voici la version complète :

---

```markdown
# 🌀 Labyrinth Game – C++

This project was developed as part of a graded C++ assignment at **Polytech Clermont-Ferrand (IMDS 4A)**.  
The goal was to implement a console-based labyrinth game where the player must reach the exit while avoiding walls (and, in the advanced version, an enemy).  

Two versions of the game are included:  
- **Version 1 (basic)**: only the player moves.  
- **Version 2 (improved)**: an enemy is added, and the player can also import custom labyrinths from text files.  

---

## 🎮 Game Rules

### Basic Version
- The player is represented by **`P`**.  
- The exit is represented by **`S`**.  
- Walls are represented by **`o`**.  
- Movement is controlled by:  
  - `d` → right  
  - `g` → left  
  - `h` → up  
  - `b` → down  
- Movement is only allowed on corridors (not walls).  
- If the player tries to move into a wall, an error message is displayed.  
- **Victory condition**: reach the exit **S**.

### Improved Version
- An enemy **`E`** is added.  
- The enemy moves randomly after each player move, only on corridors.  
- **Defeat condition**: if the enemy reaches the player **P**.  
- **Victory condition**: the player reaches the exit **S** before being caught.  

---

## 🗂️ Custom Labyrinths (Version 2)

The user can create and play with their own labyrinths from text files.  
We provide three example files in the project:  
- `labyrinthe_facile.txt` → simple labyrinth.  
- `labyrinthe_difficile.txt` → more complex labyrinth.  
- `labyrinthe_test.txt` → invalid format (useful to test error handling).  

You can also create your own labyrinths, provided they respect the following format:  
- `o` → walls  
- `2` → corridors where the player and enemy can move (we used `2` instead of space for file parsing reasons).  
- `P` → player  
- `E` → enemy  
- `S` → exit  

By convention, every labyrinth must be surrounded by walls, except at the exit position.

When the game starts, the player can choose between:  
1. Play with the default labyrinth.  
2. Import a custom labyrinth from a text file (must end with `.txt`).  

---

## 🖼️ Object Mapping

Each object in the labyrinth has been given a numeric type for easier differentiation:  
- `1` → Wall  
- `2` → Corridor  
- `3` → Exit  
- `4` → Player  
- `5` → Enemy  

---

## 📂 Repository Structure

```

.
├── src/
│   ├── v1/   # Basic version (player only)
│   └── v2/   # Improved version (enemy + custom labyrinths)
├── labyrinths/  # Example labyrinth text files
├── report/      # Project report
└── README.md

````

---

## 🚀 How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/<repo-name>.git
   cd <repo-name>
````

2. Go to the desired version:

   ```bash
   cd src/v1   # or src/v2
   ```

3. Compile with g++:

   ```bash
   g++ -o labyrinth main.cpp *.cpp
   ```

4. Run the game:

   ```bash
   ./labyrinth
   ```

---

## 📝 Report

A detailed report describing the game rules, implementation choices, and improvements can be found in the [`report/`](./report) folder.

---

## 👥 Authors

Project developed by **Joseph** and teammate as part of the graded C++ assignment at **Polytech Clermont-Ferrand (IMDS 4A)**.

```

---

Veux-tu que je t’ajoute aussi un **diagramme ASCII d’un petit labyrinthe** (exemple minimal) pour illustrer directement dans le README ?
```
