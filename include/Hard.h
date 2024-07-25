// Hard.h
#ifndef HARD_H
#define HARD_H

// 定義金塊或炸彈的類
class Hard {
public:
    // 建構函數：初始化金塊或炸彈並隨機生成位置
    Hard();

    // 重新隨機生成金塊或炸彈的位置
    void respawn();

    // 獲取金塊或炸彈的橫座標
    int getX() const;

    // 獲取金塊或炸彈的縱座標
    int getY() const;

private:
    int x, y; // 金塊或炸彈的座標
};

#endif // HARD_H
