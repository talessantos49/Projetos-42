## Introduction
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements. 

In this project, the goal is for the player to collect all the collectibles on the map before going to an exit. However, the game must follow a set of rules which are described bellow.

## Rules
The executable `so_long` will receive a `.ber` filetype map as the only argument, otherwise, the game must exit with a `Error\n` message. Also, if any of the following checks fail, the game must end with an `Error\n` followed by a custom message:
- The map must be rectangular.
- There must be at least one collectable `C`, one exit `E`, and one player `P` on the map.
- The map must be surrounded by walls `1`'s.
- Only the following characters are valid: "`01CPE`" where `0` indicates the floor area, `1` walls, `C` collectables, `P` Player, and `E` an exit.
- The map must be a valid route.
- Any leak or invalid size read can be exist.

You can create your own map (just remember the rules to create a valid map described above). For exemple, here is an valid map and its demo:
```bash
# my_map.ber
111111111111111111111111111111111
1P0000000000000000000000000000001
100000001111100000011111000000001
100000011111100000111111100000001
100000110001100001100C01100000001
100001100001100000000011000000001
100011111011100000000110000000001
100111111C11100000001100000000001
1000000000111000000110C0000000001
100000000011100000111111000000001
1000000000000000000000000000000E1
111111111111111111111111111111111
```

## How it works
To handle the graphic part of the project, we are using a library called **[MinilibX](https://github.com/42Paris/minilibx-linux)** (A simple X-Window programming API, designed for students, suitable for X-beginners). Despite its leak issues and limitations, is pretty fun to work with.

Feel free to ask me how the code works. In summary, im using gnl and split to create a matrix that represents the map, some functions which scan the whole matrix and validates the map, and some hooks that MinilibX provide us in order to control game events.