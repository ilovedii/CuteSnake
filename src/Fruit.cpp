// Fruit.cpp
#include "../include/Fruit.h"
#include <cstdlib>
#include <ctime>

// 建構函數：初始化水果並隨機生成位置
Fruit::Fruit() {
    std::srand(static_cast<unsigned>(std::time(0)) +1);
    respawn();
}

// 重新隨機生成水果的位置
void Fruit::respawn() {
    x = std::rand() % 29; // 網格寬度
    y = std::rand() % 19; // 網格高度
}

// 獲取水果的橫座標
int Fruit::getX() const {
    return x;
}

// 獲取水果的縱座標
int Fruit::getY() const {
    return y;
}
