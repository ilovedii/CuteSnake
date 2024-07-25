# CuteSnake
Welcome to the reinvented classic Snake game, by using the Simple and Fast Multimedia Library (SFML)! Experience the nostalgic game in two unique versions: Day and Night, each offering different levels of excitement and challenge.

## Features
- Two Distinct Versions: Switch between Day and Night modes for varied visual experiences and gameplay mechanics.

## Day Mode
- Classic Gameplay: Control the snake to eat fruits and increase its length.
- Different Fruits, Different Scores: Various fruits appear on the screen, each with a different score value.
- Simple Objective: Avoid colliding with the walls or the snake's own body to stay alive.

## Night Mode
- Dynamic Challenges: Encounter eagles, bombs, and gold for an added layer of excitement.
  - Eagles: Bumping into an eagle decreases your score, but the eagle will fly away.
  - Bombs and Gold: Both items appear randomly; collecting them will increase your score.
  
## Requirments
- C++11 or higher
- SFML library (2.6.1 or later)
- A compatible compiler (e.g., g++, clang++)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/ilovedii/CuteSnake.git
   cd CuteSnake
   ```

2. Install SFML:

   On macOS:
   ```bash
   brew install sfml
   ```

   On Ubuntu:
   ```bash
   sudo apt-get install libsfml-dev
   ```

3. Build the project using Makefile:

   ```bash
   make
   ```

4. Run the game:

   ```bash
   ./build/SnakeGame
   ```
## Usage

### Controls

- **Arrow Keys**: Control the direction of the snake.
  - `Up Arrow`: Move the snake up.
  - `Down Arrow`: Move the snake down.
  - `Left Arrow`: Move the snake left.
  - `Right Arrow`: Move the snake right.
- **P Key**: Pause and resume the game.
- **Escape Key**: Exit the game.
- **R Key**: Retuen to Start page.

  ## Project Structure

```
.
├── Makefile           # Build configuration
├── README.md          # Project documentation
├── src                # Source files
│   ├── main.cpp       # Entry point of the game
│   ├── Game.cpp       # Main game logic
│   ├── Snake.cpp      # Snake class implementation
│   ├── Fruit.cpp      # Fruit class implementation
│   ├── Eagle.cpp      # Eagle class implementation
│   ├── Night.cpp      # Night mode logic
│   ├── Hard.cpp       # Additional difficulty logic
│   ├── ScoreBoard.cpp # Scoreboard implementation
│   ├── StartScreen.cpp# Start screen logic
├── include            # Header files
│   ├── Game.h         # Game class declaration
│   ├── Snake.h        # Snake class declaration
│   ├── Fruit.h        # Fruit class declaration
│   ├── Eagle.h        # Eagle class declaration
│   ├── Night.h        # Night mode declaration
│   ├── Hard.h         # Additional difficulty declaration
│   ├── ScoreBoard.h   # Scoreboard declaration
│   ├── StartScreen.h  # Start screen declaration
├── assets             # Assets for the game
│   ├── fonts          # Font files
│   ├── sounds         # Sound effect files
│   └── textures       # Texture files
└── build              # Compiled binary and object files
    └── SnakeGame      # Executable file

```

---
Enjoy playing the game ~
