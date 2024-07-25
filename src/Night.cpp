//Night.cpp
#include "../include/Night.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstdlib>

const int GRID_WIDTH = 30; // 網格寬度
const int GRID_HEIGHT = 30; // 網格高度
const int TILE_SIZE = 20; // 單位格子尺寸
const int WINDOW_WIDTH = TILE_SIZE * GRID_WIDTH + 200; // 窗口寬度
const int WINDOW_HEIGHT = TILE_SIZE * GRID_HEIGHT; // 窗口高度
static int choice = 0;
int cool_stuff = 0;

// 建構函數：初始化遊戲窗口和元件
Night::Night(sf::RenderWindow& window) :
	snake(),
	fruit(),
	hard(),
	eagle(),
	scoreboard(),
	window(window),
	isPaused(false),
	gameOver(false),
	gameReset(false),
	gamestate(0),
	startScreen(WINDOW_WIDTH, WINDOW_HEIGHT)
{
	tileTexture.loadFromFile("assets/textures/white.png");
	tileSprite.setTexture(tileTexture);

	if (!backgroundTexture.loadFromFile("assets/textures/night.png")) {
		std::cerr << "Error: Failed to load night.png" << std::endl;
		return;
	}
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(
			static_cast<float>(WINDOW_WIDTH) / backgroundTexture.getSize().x,
			static_cast<float>(WINDOW_HEIGHT) / backgroundTexture.getSize().y
			);

	fruitTexture1.loadFromFile("assets/textures/apple.png");
	fruitTexture2.loadFromFile("assets/textures/banana.png");
	fruitTexture3.loadFromFile("assets/textures/orange.png");
	fruitTexture4.loadFromFile("assets/textures/grape.png");
	fruitSprite1.setTexture(fruitTexture1);
	fruitSprite2.setTexture(fruitTexture2);
	fruitSprite3.setTexture(fruitTexture3);
	fruitSprite4.setTexture(fruitTexture4);
	fruitSprite1.setScale(0.021f, 0.021f);
	fruitSprite2.setScale(0.15f, 0.15f);
	fruitSprite3.setScale(0.11f, 0.11f);
	fruitSprite4.setScale(0.1f, 0.1f);

	bombTexture.loadFromFile("assets/textures/bomb.png");
	bombSprite.setTexture(bombTexture);
	bombSprite.setScale(0.03f, 0.03f);

	goldTexture.loadFromFile("assets/textures/gold.png");
	goldSprite.setTexture(goldTexture);
	goldSprite.setScale(0.1f,0.1f);

	eagleTexture.loadFromFile("assets/textures/eagle.png");
	eagleSprite.setTexture(eagleTexture);
	eagleSprite.setScale(0.1f,0.1f);


	snakeBodyTexture.loadFromFile("assets/textures/snakebody.png");
	snakeBodySprite.setTexture(snakeBodyTexture);

	snakeheadTexture.loadFromFile("assets/textures/snakehead.png");
	snakeheadSprite.setTexture(snakeheadTexture);

	gameOverTextTexture.loadFromFile("assets/textures/gameover_n.png");
	gameOverTextSprite.setTexture(gameOverTextTexture);
	gameOverTextSprite.setScale(0.5f,0.5f);

	if (!font.loadFromFile("assets/fonts/font.ttf")) {
		std::cerr << "Error: Failed to load font.ttf" << std::endl;
		return;
	}
	if (!font2.loadFromFile("assets/fonts/font2.ttf")) {
		std::cerr << "Error: Failed to load font2.ttf" << std::endl;
		return;
	}
	if (!font3.loadFromFile("assets/fonts/font3.ttf")) {
		std::cerr << "Error: Failed to load font3.ttf" << std::endl;
		return;
	}
	if (!font4.loadFromFile("assets/fonts/font4.ttf")) {
		std::cerr << "Error: Failed to load font4.ttf" << std::endl;
		return;
	}
	if (!font5.loadFromFile("assets/fonts/font5.ttf")) {
		std::cerr << "Error: Failed to load font5.ttf" << std::endl;
		return;
	}

	if (!eatSoundBuffer.loadFromFile("assets/audio/eat_apple.wav")) {
		std::cerr << "Error: Failed to load eat_apple.wav" << std::endl;
		return;
	}
	eatSound.setBuffer(eatSoundBuffer);
	eatSound.setVolume(30);

	if (!bombSoundBuffer.loadFromFile("assets/audio/bomb.wav")) {
		std::cerr << "Error: Failed to load bomb.wav" << std::endl;
		return;
	}
	bombSound.setBuffer(eatSoundBuffer);
	bombSound.setVolume(30);


	if (!backgroundmusic.openFromFile("assets/audio/night.wav")) {
		std::cerr << "Error: Failed to load day.wav" << std::endl;
		return;
	}
	backgroundmusic.setVolume(100);
	backgroundmusic.setLoop(true);
	backgroundmusic.setPlayingOffset(sf::seconds(3.5));
	backgroundmusic.play();

}


void Night::run() {
	//創建一個時鐘物件
	sf::Clock clock;
	float timer = 0.0f, delay = 0.1f;

	// 主遊戲循環：當窗口未關閉時繼續執行
	while (window.isOpen()) {
		handleInput();
		// 計算自上次重置以來的經過時間（秒）
		float elapsedTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += elapsedTime;


		if (!isPaused && timer > delay && !gameOver) {
			timer = 0.0f;
			update();
		}
		if (gameReset) {
			gameReset = true;
			return;
		}

		render();
	}
}
// 處理输入事件
void Night::handleInput() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (gamestate == false) {
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
				gamestate = true;
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			// debug: 印出所有KeyPressed
			std::cout << "Key pressed: " << event.key.code << std::endl;

			// 檢查是否按下 P
			if (event.key.code == sf::Keyboard::P) {
				isPaused = !isPaused; // 切換暫停狀態
				if(isPaused){
					backgroundmusic.pause();
				}else{
					backgroundmusic.play();
				}
			}
			// 檢查是否按下 ESC
			if (event.key.code == sf::Keyboard::Escape) {
				window.close(); // 關掉視窗
			}
			// 檢查是否按下 R
			if (event.key.code == sf::Keyboard::R) {
				gameReset = true;
				reset();
			}
		}
	}
	// 更改蛇的方向
	if (!isPaused) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) snake.changeDirection(Left);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) snake.changeDirection(Right);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) snake.changeDirection(Up);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) snake.changeDirection(Down);
	}
}


// 更新遊戲狀態
void Night::update() {

	snake.move();
	eagle.move(27,27);

	if(snake.isSelfCollision()){
		snake.modifiedSnake();
		int newSize = snake.getBody().size();
		scoreboard.resetScore();
		int addPoints = newSize * 10 - 10;
		scoreboard.increaseScore(addPoints);
	}

	if(snake.isOutOfBounds()) {
		backgroundmusic.stop();
		gameOver = true;
		return;
	}

	// 如果蛇吃到水果，增加長度並重新生成水果
	if (snake.getHeadPosition() == sf::Vector2i(fruit.getX(), fruit.getY()) ||  snake.getHeadPosition() == sf::Vector2i(fruit.getX()+1, fruit.getY()) || snake.getHeadPosition() == sf::Vector2i(fruit.getX(), fruit.getY()+1) || snake.getHeadPosition() == sf::Vector2i(fruit.getX()+1, fruit.getY()+1)) {
		std::srand(static_cast<unsigned>(std::time(0)));
		snake.grow();
		eatSound.play();
		fruit.respawn();

		if(choice == 0){
			scoreboard.increaseScore(5);
		}else if(choice == 1){
			scoreboard.increaseScore(10);
		}else if(choice == 2){
			scoreboard.increaseScore(15);
		}else {
			scoreboard.increaseScore(20);
		}

		choice = rand()%4;
	}

	// 如果蛇吃到金子或炸彈
	if (snake.getHeadPosition() == sf::Vector2i(hard.getX(), hard.getY()) ||  snake.getHeadPosition() == sf::Vector2i(hard.getX()+1, hard.getY()) || snake.getHeadPosition() == sf::Vector2i(hard.getX(), hard.getY()+1) || snake.getHeadPosition() == sf::Vector2i(hard.getX()+1, hard.getY()+1)) {
		std::srand(static_cast<unsigned>(std::time(0)));
		hard.respawn();

		if(cool_stuff == 0){
			snake.shrink();
			scoreboard.increaseScore(-50);
			bombSound.play();
			if(scoreboard.getScore() < 0 || snake.getBody().size() == 1){
				gameOver = true;
				return;
			}

		}else if(cool_stuff == 1){
			scoreboard.increaseScore(100);
		}

		cool_stuff = rand()%2;

	}

	//老鷹飛飛
	//eagle.respawn();

	if (snake.getHeadPosition() == sf::Vector2i(eagle.getX(), eagle.getY()) || snake.getHeadPosition() == sf::Vector2i(eagle.getX(), eagle.getY() +1) || snake.getHeadPosition() == sf::Vector2i(eagle.getX() +1, eagle.getY()) || snake.getHeadPosition() == sf::Vector2i(eagle.getX() +1, eagle.getY() +1 ) || snake.getHeadPosition() == sf::Vector2i(eagle.getX()+2, eagle.getY()+2) || snake.getHeadPosition() == sf::Vector2i(eagle.getX()+2, eagle.getY()) || snake.getHeadPosition() == sf::Vector2i(eagle.getX(), eagle.getY()+2)||snake.getHeadPosition() == sf::Vector2i(eagle.getX() +1, eagle.getY() +2) || snake.getHeadPosition() == sf::Vector2i(eagle.getX() +2, eagle.getY() +1)) {
		scoreboard.increaseScore(-20);
		if(scoreboard.getScore() < 0 ){
				gameOver = true;
				return;
			}
	}

}

void Night::render() {
	window.clear();
	// 繪製背景圖片
	window.draw(backgroundSprite);

	//繪製蛇頭
	sf::Vector2i headPos = snake.getHeadPosition();
	snakeheadSprite.setPosition(headPos.x * TILE_SIZE, headPos.y * TILE_SIZE);
	window.draw(snakeheadSprite);

	// 繪製蛇身
	const auto& body = snake.getBody();
	for (size_t i = 1; i < body.size(); ++i) {
		snakeBodySprite.setPosition(body[i].x * TILE_SIZE, body[i].y * TILE_SIZE);
		window.draw(snakeBodySprite);
	}

	//score table
	for (int i = GRID_WIDTH; i < WINDOW_WIDTH ; i = i + TILE_SIZE) {
		for (int j = 0; j < WINDOW_HEIGHT;j = j + TILE_SIZE) {
			tileSprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
			window.draw(tileSprite);
		}
	}

	// 繪製水果

	if(fruit.getX() != hard.getX() || fruit.getY() != hard.getY()){
		if(choice == 0){
			fruitSprite1.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
			window.draw(fruitSprite1);
		}
		else if(choice == 1){
			fruitSprite2.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
			window.draw(fruitSprite2);
		}
		else if(choice == 2){
			fruitSprite3.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
			window.draw(fruitSprite3);

		}
		else if(choice == 3){
			fruitSprite4.setPosition(fruit.getX() * TILE_SIZE, fruit.getY() * TILE_SIZE);
			window.draw(fruitSprite4);

		}

		//繪製炸彈
		if(cool_stuff == 0){
			bombSprite.setPosition(hard.getX() * TILE_SIZE, hard.getY() * TILE_SIZE);
			window.draw(bombSprite);
		}else if (cool_stuff == 1) {
			goldSprite.setPosition(hard.getX() * TILE_SIZE, hard.getY() * TILE_SIZE);
			window.draw(goldSprite);
		}

		//繪製老鷹
		//sf::Vector2i eaglePos = eagle.getPosition();
    	eagleSprite.setPosition(eagle.getX() * TILE_SIZE, eagle.getY() * TILE_SIZE);
    	window.draw(eagleSprite);
	}


	// 如果遊戲暫停，顯示paused
	if (isPaused) {
		sf::Text pausedText;
		pausedText.setFont(font3);
		pausedText.setCharacterSize(30);
		pausedText.setFillColor(sf::Color(137, 155, 156));
		pausedText.setStyle(sf::Text::Bold);
		pausedText.setString("Paused");
		pausedText.setPosition(WINDOW_WIDTH - pausedText.getGlobalBounds().width - 70,
				WINDOW_HEIGHT/2  - pausedText.getGlobalBounds().height -50);
		window.draw(pausedText);
	}

	//繪製背景分數
	scoreText.setFont(font5);
	scoreText.setCharacterSize(35);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setString("Score:" + std::to_string(scoreboard.getScore()));
	scoreText.setPosition(window.getSize().x - 190, window.getSize().y - 100); // 调整文本位置，确保不会与背景重叠
	scoreText.setFillColor(sf::Color(153, 204, 204, 255));
	window.draw(scoreText);

	// 如果遊戲結束，顯示Game Over
	if (gameOver) {
		gameOverTextSprite.setPosition(WINDOW_WIDTH/2 - gameOverTextSprite.getGlobalBounds().width/2 - 90,
				WINDOW_HEIGHT/2 - gameOverTextSprite.getGlobalBounds().height/2 - 30);
		window.draw(gameOverTextSprite);
		backgroundmusic.stop();

	}

	// 顯示已繪製的畫面
	window.display();
}


// 重置遊戲
void Night::reset() {
	snake = Snake();
	fruit.respawn();
	hard.respawn();
	eagle.respawn();
	scoreboard.resetScore();
	isPaused = false;
	gameOver = false;
	backgroundmusic.setPlayingOffset(sf::seconds(3.5));
	backgroundmusic.play();
}

bool Night::isGameoverClicked(sf::Vector2f mousePos){
	return gameOverTextSprite.getGlobalBounds().contains(mousePos);
}
