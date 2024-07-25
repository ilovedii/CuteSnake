#include "../include/Snake.h"
#include "../include/Game.h"
#include "../include/Fruit.h"
#include "../include/Night.h"
#include "../include/StartScreen.h"
#include "../include/Hard.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

const int GRID_WIDTH = 30; // 網格寬度
const int GRID_HEIGHT = 30; // 網格高度
const int TILE_SIZE = 20; // 單位格子尺寸
const int WINDOW_WIDTH = TILE_SIZE * GRID_WIDTH + 200; // 窗口寬度
const int WINDOW_HEIGHT = TILE_SIZE * GRID_HEIGHT; // 窗口高度

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    StartScreen startScreen(WINDOW_WIDTH, WINDOW_HEIGHT);

    bool gameStarted = false;
    bool isNightVersion = false;
    bool gameover = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                if (!gameStarted) {
                    if (startScreen.isDayButtonClicked(mousePos)) {
                        isNightVersion = false;
                        gameStarted = true;
                    } else if (startScreen.isNightButtonClicked(mousePos)) {
                        isNightVersion = true;
                        gameStarted = true;
                    }
                } else if (gameover) {
					while(true){};
                    // Check if the "Game Over" image is clicked
                    if (isNightVersion) {
                        Night game(window);
                        if (game.isGameoverClicked(mousePos)) {
                            gameover = false;
                            gameStarted = false;
                        }
                    } else {
                        Game game(window);
                        if (game.isGameoverClicked(mousePos)) {
                            gameover = false;
                            gameStarted = false;
                        }
                    }
                }
            }
        }

        window.clear();
        if (!gameStarted) {
            startScreen.draw(window);
        } else {
            if (isNightVersion) {
                Night game(window); // Assume you have a NightGame class
                game.run();
                //gameover = game; // Update the game over status
            } else {
                Game game(window);
                game.run();
                //gameover = game.gameOver(); // Update the game over status
            }
        }
		gameover = true;
		gameStarted = false;
        window.display();
    }

    return 0;
}
