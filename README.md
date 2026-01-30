# cub3d

cub3d is a 42 School graphics project that recreates the core mechanics of Wolfenstein 3D using raycasting. A 2D map is rendered as a 3D first-person view with textured walls, floor, ceiling, and movement controls.

## Overview

The program parses `.cub` configuration files that define textures, colors, and a 2D map. A raycasting engine projects the map into a 3D perspective. The player moves with WASD and rotates the camera to navigate the maze.

## Composition

- **cub3d.c** — entry point
- **source/parsing/** — parser, map validation, `map_check.c`
- **source/libx/** — MiniLibX setup, events, raycast, textures, rendering
- **source/gameplay/** — player movement
- **source/cleanup/** — memory and resource cleanup
- **source/** — `init.c`, `math.c`, `utils.c`
- **libraries/** — libft, MiniLibX
- **assets/** — sample maps (`.cub`) and textures (`.xpm`)

## Features

- **Raycasting engine** — 3D projection from 2D map
- **Texture mapping** — wall textures (N, S, E, W)
- **Floor and ceiling** — optional colors or textures
- **Map parsing** — `.cub` config (resolution, paths, colors, map grid)
- **Movement** — WASD, mouse/camera rotation
- **Clean exit** — ESC, window close

## Technology

- C (C99)
- MiniLibX
- libft (custom)
- Linux: X11, Xext

## Setup

Build (requires MiniLibX in `libraries/minilibx`):

```bash
make
```

Run with a map file:

```bash
./cub3D assets/maps/example.cub
./cub3D test.cub
```

## Makefile targets

| Target   | Description             |
|----------|-------------------------|
| `all`    | Build `cub3D`           |
| `clean`  | Remove object files     |
| `fclean` | Remove objects and binary |
| `re`     | Fclean then rebuild     |

## Map format (.cub)

- `R` width height — resolution
- `NO`, `SO`, `EA`, `WE` — texture paths
- `F`, `C` — floor and ceiling colors (RGB)
- Map: `0` walkable, `1` wall, `N/S/E/W` spawn and direction

## Notes

- Subject: `cub3d_subject.pdf`
- Rank 2 graphics project
- Often done as a team project
