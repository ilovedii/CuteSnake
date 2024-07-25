// Hard.cpp
#include "../include/Hard.h"
#include <cstdlib>
#include <ctime>

// 建構函數：初始化炸彈或金塊並隨機生成位置
Hard::Hard() {
    std::srand(static_cast<unsigned>(std::time(0)));
    respawn();
}

// 重新隨機生成炸彈或金塊的位置
void Hard::respawn() {
    x = std::rand() % 27; // 網格寬度
    y = std::rand() % 27; // 網格高度
}

// 獲取炸彈或金塊的橫座標
int Hard::getX() const {
    return x;
}

// 獲取酷炸彈或金塊的縱座標
int Hard::getY() const {
    return y;
}
