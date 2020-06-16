#pragma once
#include "math.h"

////原点と角度と半径を送ると位置が返ってくる 右回り
void GetCirclePoint(float posX, float posY, float r, float  angle, float* px, float* py);
//底辺と高さから斜辺を取り出す
float GetHypotenuse(int x, int y);
float GetCosWave(float angle);
float GetSinWave(float angle);