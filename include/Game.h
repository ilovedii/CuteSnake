// Game.h
#ifndef GAME_H
#define GAME_H

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Snake.h"
#include "Fruit.h"
#include "ScoreBoard.h"
#include "StartScreen.h"


// 表示整個貪吃蛇遊戲的類
class Game {
public:
    // 建構函數：初始化遊戲窗口和元件
    Game(sf::RenderWindow& window);

    // 運行遊戲循環
    void run();

	bool isGameoverClicked(sf::Vector2f mousePos);

private:
    // 處理用戶輸入事件
    void handleInput();

    // 更新遊戲狀態
    void update();

    // 渲染遊戲畫面
    void render();

    sf::RenderWindow& window; // 渲染窗口
    Snake snake;             // 貪吃蛇
    Fruit fruit;             // 水果
    ScoreBoard scoreboard;   //計分板
    StartScreen startScreen; // 起始畫面

	//圖片
	sf::Texture tileTexture, snakeheadTexture, snakeBodyTexture, fruitTexture1, fruitTexture2,fruitTexture3,fruitTexture4, gameOverTextTexture; // 紋理
    sf::Sprite tileSprite, snakeheadSprite, snakeBodySprite, fruitSprite1, fruitSprite2, fruitSprite3, fruitSprite4, gameOverTextSprite;    // 物件精靈
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	
	//字體
	sf::Font font, font2, font3, font4, font5;
    sf::Text scoreText;
	
	//音效
	sf::SoundBuffer eatSoundBuffer;
	sf::Sound eatSound;
	//背景音樂
	sf::Music backgroundmusic;
	sf::RectangleShape scoreBackground;
    bool isPaused; // 暫停狀態
    void reset(); // 重置遊戲
    bool gameOver; // 遊戲結束狀態
	bool gamestate; // 遊戲狀態
	bool gameRestart;//遊戲重新開始(可選擇version)
};

#endif // GAME_H
