#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <vector>

class ScoreBoard{
public:
    ScoreBoard();//建構函數

    int getScore();//獲取分數版的值

    int increaseScore(int value); //增加分數

    int decreaseScore(int value);//減少分數

    void resetScore();//重置分數為10
    
private:
    int score; //分數
};

#endif
