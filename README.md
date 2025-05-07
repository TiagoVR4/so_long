# SO_LONG

## 📝 Description

So_long is a 2D puzzle game developed as part of the 42 School curriculum. In this game, you control a character navigating through a maze to collect items and reach an exit. The unique twist: **every tile you walk on becomes a wall**, making your path choices permanent and strategic.

This mechanic transforms a simple collection game into a challenging puzzle where planning ahead is essential. You'll need to carefully consider each move to ensure you can collect all items and reach the exit without getting trapped.

## 🎮 Game Features

- **Unique Movement Mechanic**: Each tile you step on transforms into a wall, making backtracking impossible
- **Path Validation**: All maps are validated to ensure they have a solution
- **Reset Function**: Press 'R' to restart the level when you get stuck
- **Dynamic Map Rendering**: Clean visual representation of the game state
- **Collectibles**: Gather all items before reaching the exit

## 🕹️ Controls

- **W / Up Arrow**: Move up
- **A / Left Arrow**: Move left
- **S / Down Arrow**: Move down
- **D / Right Arrow**: Move right
- **R**: Restart the current level
- **ESC**: Exit the game

## 🖼️ Game Elements

- `0`: Empty space (floor)
- `1`: Wall
- `P`: Player starting position
- `C`: Collectible
- `E`: Exit

## 🛠️ Installation

### Requirements

- GCC compiler
- Make
- X11 development libraries

### Building the Game

1. Clone the repository:
   ```bash
   git clone https://github.com/TiagoVR4/so_long.git
   cd so_long
   ```

2. Compile the game:
   ```bash
   make
   ```

### Running the Game

```bash
./so_long maps/[map_file].ber
```

## 🗺️ Creating Maps

Maps are stored in `.ber` files with the following rules:

- Maps must be rectangular
- Maps must be enclosed by walls (`1`)
- Maps must contain exactly one player (`P`), at least one collectible (`C`), and at least one exit (`E`)
- Every collectible must be reachable
- There must be a valid path to the exit

### Example Map

```
1111111111111
1P000000000C1
1000111111001
10001C0000001
1000111111001
10000000C0001
1000111111001
1C00000000E01
1111111111111
```

## 🏗️ Project Structure

- [`/src`](src ): Source code files
- [`/maps`](maps ): Map files in .ber format
- [`/img`](img ): Game sprites
- [`/libft`](libft ): Custom C library
- [`/minilibx-linux`](minilibx-linux ): Graphics library

## 🎯 Design Strategy

This game implements a unique variant of path-finding puzzles known as "self-avoiding walk puzzles" or "one-way path puzzles." The player's challenge is to find a specific path that allows collecting all items without creating a situation where essential parts of the map become unreachable.

## 📋 Implementation Details

- **MiniLibX Graphics Library**: Used for window management and rendering
- **Path Validation Algorithm**: Implements a recursive depth-first search to verify map solvability
- **Dynamic Memory Management**: Careful handling of allocated resources to prevent memory leaks
- **Error Handling**: Robust validation for maps and game states

## 🧩 Game Logic

The core game logic revolves around the concept of each step creating a wall behind you. This transforms the gameplay from a simple collection task to a complex puzzle where every move must be planned carefully.

## 👨‍💻 Author

- Tiago Reis - [GitHub Profile](https://github.com/TiagoVR4)

## 📜 License

This project was created as part of the curriculum at 42 School.