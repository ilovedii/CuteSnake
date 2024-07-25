#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>

class StartScreen {
public:
    StartScreen(float width, float height);
    void draw(sf::RenderWindow& window);
	bool isDayButtonClicked(sf::Vector2f mousePos);
    bool isNightButtonClicked(sf::Vector2f mousePos);

private:
    sf::Font font;
    sf::Text title;
    sf::Text instructions;
    sf::Text dayText;
    sf::Text nightText;
    sf::Sprite dayButton;
    sf::Sprite nightButton;
    sf::Texture dayButtonTexture;
    sf::Texture nightButtonTexture;
	sf::Texture backgroundTexture,snakepicTexture;
	sf::Sprite backgroundSprite,snakepicSprite;
	
};

#endif // STARTSCREEN_H
