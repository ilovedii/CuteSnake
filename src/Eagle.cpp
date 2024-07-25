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

   
	//撞到上界或下界
	if (x <= 0 || x >= 29 - 1) {
        dx = -dx;
    }
    if (y <= 0 || y >= 29 - 1) {
        dy = -dy;
    }
}


