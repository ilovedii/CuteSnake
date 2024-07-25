// Eagle.cpp
#include "../include/Eagle.h"
#include <cstdlib>
#include <ctime>

// 建構函數：初始化老鷹並隨機生成位置
Eagle::Eagle()
{
    std::srand(static_cast<unsigned>(std::time(0)));
    respawn();
}

// 重新隨機生成老鷹的位置
void Eagle::respawn() {
    x = std::rand() % 27; // 網格寬度
    y = std::rand() % 27; // 網格高度
	dx = (std::rand() % 2) * 2 - 1;
    dy = (std::rand() % 2) * 2 - 1;
}

// 獲取老鷹的橫座標
int Eagle::getX() const {
    return x;
}

// 獲取老鷹的縱座標
int Eagle::getY() const {
    return y;
}

void Eagle::move(int screenWidth, int screenHeight) {

	x += dx;
    y += dy;

    /*int direction = std::rand() % 4;
    switch (direction) {
        case 0: // 向左移動
            x = (x > 0) ? x - 1 : 29;
            break;
        case 1: // 向右移動
            x = (x < 29) ? x + 1 : 0;
            break;
        case 2: // 向上移動
            y = (y > 0) ? y - 1 : 29;
            break;
        case 3: // 向下移動
            y = (y < 29) ? y + 1 : 0;
            break;
    }*/


	if (x <= 0 || x >= 29 - 1) {
        dx = -dx;
    }
    // 撞到上或下界
    if (y <= 0 || y >= 29 - 1) {
        dy = -dy;
    }
}

/*sf::Vector2i Eagle::getPosition() const {
    return ;
}*/

