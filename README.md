# So_Long

**so_long** is a project that involves creating a simple 2D game using the **MiniLibX** library. The objective of the game is to navigate through a map, collect items, and reach the exit.

## Compilation

To compile the project, run the following command:

```bash
make
```

## Usage

Once compiled, you can run the game with:

```bash
./so_long assets/map/map.ber
```

> **Note:** Replace `map.ber` with any other map file located in the `assets/map` directory.

## Controls

- **W** : Move up  
- **A** : Move left  
- **S** : Move down  
- **D** : Move right  
- **ESC** : Exit the game  

## Project Structure

```
so_long/
├── src/            # Source files
├── include/        # Header files
├── assets/
│   └── map/        # Map files (.ber)
├── Makefile
└── README.md
```

## Dependencies

- **MiniLibX**: Make sure you have the MiniLibX library installed on your system.
  
For macOS:
```bash
brew install mlx
```
