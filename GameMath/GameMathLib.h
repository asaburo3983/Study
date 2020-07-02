#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define AngleToRadian(angle) (angle/180.0*3.14)
#define RadianToAngle(radian) (radian*180.0/3.14)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//三角関数//////////////////////////////
////原点と角度と半径を送ると位置が返ってくる 右回り
void GetCirclePoint(float posX, float posY, float r, float  angle, float* px, float* py);
//底辺と高さから斜辺を取り出す
float GetHypotenuse(int x, int y);
float GetCosWave(float angle);
float GetSinWave(float angle);
////////////////////////////////////////////////////////////
//当たり判定//////////////////////////////
//中心点を描画軸とする四角画像の当たり判定
bool HitRect(int centerX, int centerY, int width, int height, int px, int py);

////////////////////////////////////////////////////////////
//ファイル操作//////////////////////////////
//ファイルから1行200バイト分のテキストを2次元配列に入れる ファイルはソフトでShift-JISにすること、UTF-8は文字化けする
void LoadTextFile(const char* filePath,char text[][200],int size0);

////////////////////////////////////////////////////////////