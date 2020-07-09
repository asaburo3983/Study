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
bool HitRect(int centerX, int centerY, int width, int height, int px, int py);//矩形
bool HitCircle(float posX1, float posY1, float r1, float posX2, float posY2, float r2);//円
////////////////////////////////////////////////////////////
//ファイル操作//////////////////////////////
//ファイルから1行200バイト分のテキストを2次元配列に入れる ファイルはソフトでShift-JISにすること、UTF-8は文字化けする
void LoadTextFile(const char* filePath,char text[][200],int size0);

////////////////////////////////////////////////////////////

//四角判定のクラス
class HitObject {
private:
	int x0, x1, y0, y1;
public:
	HitObject(int _x0, int _y0, int _x1, int _y1) {
		x0 = _x0;
		x1 = _x1;
		y0 = _y0;
		y1 = _y1;
	}
	bool Hit(int px, int py) {
		if (x0 <= px && px <= x1 && y0 <= py && py <= y1)
			return true;
		return false;
	}
};
