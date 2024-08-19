# Game Boy Skiddle 

## Overview

This project is a Game Boy game featuring a maze where the player, represented by a snail sprite, navigates to reach the goal. The game involves key collection to unlock doors and demonstrates efficient memory management on the Game Boy platform.

## Features

- **Player Movement**: Navigate through the maze using arrow keys.
- **Key Collection**: Collect keys to unlock doors in the maze.
- **Goal Achievement**: Reach the end of the maze to win.
- **Sprite Animation**: Smooth animation of the player sprite.
- **Memory Management**: Efficient use of Game Boy's limited memory resources.

## Files

- `main.c`: Core game logic including player movement, key collection, and win conditions.
- `MazeSprites.h`: Header file with sprite data for the maze elements.
- `MazeMap.h`: Header file with the maze map data.
- `Snail.h`: Header file with sprite data for the player character (snail).

## Understanding Memory Management

In Game Boy programming, memory management is crucial due to the limited resources available. Key considerations in this project include:

1. **Memory Usage**: The Game Boy has a limited amount of RAM (8 KB), so it's important to manage memory usage efficiently. This project uses global variables sparingly and reuses memory where possible.

2. **Tile and Sprite Data**: Graphics data is stored in the form of tiles and sprites. The `set_bkg_data` and `set_sprite_data` functions are used to load and manage these graphics efficiently.

3. **Background and Sprite Management**: Background tiles and sprites are managed separately to ensure smooth rendering and minimize memory usage. The game dynamically updates the background and sprite positions based on player actions.

4. **Animation**: Sprite animation is handled by scrolling the sprite's position in small increments, reducing the need for complex animation data.

## Building the Game

To build this game, you will need the [RGBDS](https://rgbds.dev/) toolchain. Follow these steps:

1. **Install RGBDS**: Instructions are available on the [RGBDS official website](https://rgbds.dev/).

2. **Compile the Game**:
   ```sh
   rgbasm -o main.obj main.asm
   rgbasm -o MazeSprites.obj MazeSprites.asm
   rgbasm -o MazeMap.obj MazeMap.asm
   rgbasm -o Snail.obj Snail.asm
   rgblink -o game.gb main.obj MazeSprites.obj MazeMap.obj Snail.obj
   rgbfix -v -p 0 game.gb

3.**Run the Game**

Use a Game Boy emulator such as BGB to play the game.

## Gameplay

- **Movement**: Use the arrow keys to move the snail sprite around the maze.
- **Key Collection**: Collect keys to unlock doors and progress through the maze.
- **Objective**: Reach the end of the maze to win the game.

## Code Overview

- **`main.c`**: Implements the main game loop, player controls, and sprite animations. Includes functions for checking movement validity (`canplayermove`), animating sprites (`animatesprite`), and handling game logic.
- **`MazeSprites.h`**: Defines graphical data for the maze elements. This file includes tile data used for rendering the maze.
- **`MazeMap.h`**: Provides the map layout data for the maze. This file defines the arrangement of tiles in the maze.
- **`Snail.h`**: Contains graphical data for the player sprite (snail). This file includes the sprite data used to represent the player.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with improvements or bug fixes.

## Contact

For questions or suggestions, please contact [jabbas@gitam.in].
