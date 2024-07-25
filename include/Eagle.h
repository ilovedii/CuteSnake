// Eagle.h
#ifndef EAGLE_H
#define EAGLE_H

// 定義老應的類
class Eagle {
public:
    // 建構函數：初始化老鷹並隨機生成位置
    Eagle();

    // 重新隨機生成老鷹的位置
    void respawn();

	//老鷹移動
	void move(int screenWidth, int screenHeight);

    // 獲取老鷹的橫座標
    int getX() const;

    // 獲取老鷹的縱座標
    int getY() const;

private:
    int x, y; // 老鷹的座標
	int dx, dy;
};

#endif // EAGLE_H
