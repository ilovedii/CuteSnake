// Snake.cpp
#include "../include/Snake.h"

// 建構函數：初始化蛇的初始位置與方向
Snake::Snake() : direction(Down), newDirection(Down) {
    body.emplace_back(15, 10); // 初始位置
}

void Snake::changeDirection(Direction dir) {
    // 確保不會直接掉頭
    if ((direction == Up && dir != Down) ||
        (direction == Down && dir != Up) ||
        (direction == Left && dir != Right) ||
        (direction == Right && dir != Left)) {
        newDirection = dir;
    }
}

Direction Snake::getDirection() const{
    return this->direction;
}
// 移動蛇
void Snake::move() {
    direction = newDirection;  // 在移動之前更新方向

    std::vector<sf::Vector2i> newBody = body;
    // 將每一節蛇身向前移動
    for (size_t i = body.size() - 1; i > 0; --i) {
        newBody[i] = body[i - 1];
    }

    // 根據方向移動蛇頭
    switch (direction) {
        case Down: newBody[0].y += 1; break; // 向下
        case Left: newBody[0].x -= 1; break; // 向左
        case Right: newBody[0].x += 1; break; // 向右
        case Up: newBody[0].y -= 1; break; // 向上
    }
    body = newBody;
}

void Snake::modifiedSnake(){
    std::vector<sf::Vector2i> newBody = body;
     // 檢查蛇是否撞到自己
    for (size_t i = 1; i < newBody.size(); ++i) {
        if (newBody[0] == newBody[i]) {
            newBody.resize(i); // 撞到自己後縮短
            break;
        }
    }

    body = newBody;
}

// 檢查蛇頭是否超出邊界
bool Snake::isOutOfBounds() const {
    return body[0].x < 0 || body[0].x >= 30 || body[0].y < 0 || body[0].y >= 30;
}
// 增加蛇的長度
void Snake::grow() {
    body.push_back(body.back());
}

// 獲取蛇的所有節點
const std::vector<sf::Vector2i>& Snake::getBody() const {
    return body;
}

// 獲取蛇頭的位置
sf::Vector2i Snake::getHeadPosition() const {
    return body[0];
}

//確認會不會自撞
bool Snake::isSelfCollision() const {
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0] == body[i]) {
            return true;
        }
    }
    return false;
}

void Snake::shrink() {
    if (body.size() > 1) {
        body.pop_back();
    }
}
