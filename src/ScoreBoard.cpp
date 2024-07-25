#include "../include/ScoreBoard.h"

//建構函數：初始化score值為10
ScoreBoard::ScoreBoard():score(10){}
    
//獲取分數版的值
int ScoreBoard::getScore(){
    return score;
}

//增加分數
int ScoreBoard::increaseScore(int value){
    score += value;
}

//減少分數
int ScoreBoard::decreaseScore(int value){
    score -= value;
}

//重置分數為10
void ScoreBoard::resetScore(){
    score = 0;
}
