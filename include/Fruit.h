// Fruit.h
#ifndef FRUIT_H
#define FRUIT_H

// 定義水果的類
class Fruit {
public:
    // 建構函數：初始化水果並隨機生成位置
    Fruit();

    // 重新隨機生成水果的位置
    void respawn();

    // 獲取水果的橫座標
    int getX() const;

    // 獲取水果的縱座標
    int getY() const;

private:
    int x, y; // 水果的座標
};

#endif // FRUIT_H
