// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

// 枚舉定義蛇的移動方向
enum Direction {
    Down,  // 向下
    Left,  // 向左
    Right, // 向右
    Up     // 向上
};

// 定義蛇的類
class Snake {
public:
    // 建構函數：初始化蛇的初始位置與方向
    Snake();

    // 改變蛇的移動方向
    void changeDirection(Direction dir);

    // Direction getter
    Direction getDirection() const;

    // 移動蛇
    void move();

    // 增加蛇的長度
    void grow();

	// 減少蛇的長度
    void shrink();

	// 獲取蛇的所有節點
    const std::vector<sf::Vector2i>& getBody() const;

    // 獲取蛇頭的位置
    sf::Vector2i getHeadPosition() const;

    bool isOutOfBounds() const; // 新增的方法：檢查蛇頭是否超出邊界
    bool isSelfCollision() const; // 新增的方法：檢查蛇是否撞到自己
    void modifiedSnake();

private:
    std::vector<sf::Vector2i> body; // 蛇的所有節點
    Direction direction;            // 蛇的移動方向
    Direction newDirection;
    
};

#endif // SNAKE_H
