#include "../include/StartScreen.h"
#include <SFML/System/Vector2.hpp>

//Startscreen的像素自體
StartScreen::StartScreen(float width, float height) {
    if (!font.loadFromFile("assets/fonts/font_p.ttf")) {
        // Handle error
        printf("Failed to load font\n");
    }

	//設定自體、圖片等
    title.setFont(font);
    title.setString("Snake");
    title.setCharacterSize(100);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, height / 4 + 10));

    instructions.setFont(font);
    instructions.setString("Choose The Version");
    instructions.setCharacterSize(50);
    instructions.setFillColor(sf::Color::Black);
    instructions.setStyle(sf::Text::Italic);
    instructions.setPosition(sf::Vector2f(width / 2 - instructions.getGlobalBounds().width / 2, height / 2));

    if (!dayButtonTexture.loadFromFile("assets/textures/button_d.png")) {
        // Handle error
        printf("Failed to load button_d.png\n");
    }
    dayButton.setTexture(dayButtonTexture);
    dayButton.setScale(0.3f, 0.3f);
    dayButton.setPosition(sf::Vector2f(width / 2 - dayButton.getGlobalBounds().width / 2, height / 2 + 100));

    dayText.setFont(font);
    dayText.setString("Day");
    dayText.setCharacterSize(40);
    dayText.setFillColor(sf::Color::White);
    dayText.setPosition(
        sf::Vector2f(
            dayButton.getPosition().x + dayButton.getGlobalBounds().width / 2 - dayText.getGlobalBounds().width / 2,
            dayButton.getPosition().y + dayButton.getGlobalBounds().height / 2 - dayText.getGlobalBounds().height / 2 -10
        )
    );

    if (!nightButtonTexture.loadFromFile("assets/textures/button_n.png")) {
        // Handle error
        printf("Failed to load night_button.png\n");
    }
    nightButton.setTexture(nightButtonTexture);
    nightButton.setScale(0.3f, 0.3f);
    nightButton.setPosition(sf::Vector2f(width / 2 - nightButton.getGlobalBounds().width / 2, height / 2 + 200));

    nightText.setFont(font);
    nightText.setString("Night");
    nightText.setCharacterSize(40);
    nightText.setFillColor(sf::Color::White);
    nightText.setPosition(
        sf::Vector2f(
            nightButton.getPosition().x + nightButton.getGlobalBounds().width / 2 - nightText.getGlobalBounds().width / 2,
            nightButton.getPosition().y + nightButton.getGlobalBounds().height / 2 - nightText.getGlobalBounds().height / 2 -10
        )
    );

    if (!backgroundTexture.loadFromFile("assets/textures/start_screen.jpg")) {
        // Handle error
        printf("Failed to load background.png\n");
    }
    backgroundTexture.setRepeated(true); // 允许纹理重复
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, width, height)); // 设置纹理矩形以适应窗口
    backgroundSprite.setPosition(0, 0);

	if (!snakepicTexture.loadFromFile("assets/textures/snake.png")) {
        // Handle error
        printf("Failed to load snake.png\n");    
	}

	snakepicSprite.setTexture(snakepicTexture);
	snakepicSprite.scale(0.7f,0.7f);
	snakepicSprite.setPosition(sf::Vector2f(width / 2 - nightButton.getGlobalBounds().width / 2 -40, height / 4 - 150));

}

//畫出畫面
void StartScreen::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite); // 背景
    window.draw(title);
    window.draw(instructions);
    window.draw(dayButton);
    window.draw(dayText);
    window.draw(nightButton);
    window.draw(nightText);
	window.draw(snakepicSprite);
}

//點擊day按鈕->day version
bool StartScreen::isDayButtonClicked(sf::Vector2f mousePos) {
    return dayButton.getGlobalBounds().contains(mousePos);
}

//點擊night按鈕->night version
bool StartScreen::isNightButtonClicked(sf::Vector2f mousePos) {
    return nightButton.getGlobalBounds().contains(mousePos);
}

