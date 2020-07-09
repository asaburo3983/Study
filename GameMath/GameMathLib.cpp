
#include "GameMathLib.h"


//三角関数系の処理//////////////////////////////
////原点と角度と半径を送ると位置が返ってくる 右回り
void GetCirclePoint(float posX, float posY, float r, float  angle, float* px, float* py) {

	float rad = (double)angle / 180 * 3.1415;

	*px = posX + r * cos(rad);
	*py = posY + r * sin(rad);

}
//底辺と高さから斜辺を取り出す
float GetHypotenuse(int x, int y) {
	return pow(pow(x, 2) + pow(y, 2), 0.5);
}

float GetCosWave(float angle) {
	return 	cos((double)angle / 180 * 3.1415);
}
float GetSinWave(float angle) {
	return 	sin((double)angle / 180 * 3.1415);
}
////////////////////////////////////////////////////////////
//当たり判定の処理//////////////////////////////
//四角の当たり判定
bool HitRect(int centerX, int centerY, int width, int height, int px, int py) {
	if (px < centerX - width / 2 && px < centerX + width / 2) {
		if (py < centerY - height / 2 && py < centerY + height / 2) {
			return true;//当たっている
		}
	}
	return false;
}
//円の当たり判定
bool HitCircle(float posX1, float posY1, float r1, float posX2, float posY2, float r2) {

	float distX, distY;//x&yの距離
	float dist;//点同士の斜辺の距離

	distX = posX1 - posX2;//距離を求める
	distY = posY1 - posY2;

	dist = sqrt(distX*distX + distY * distY);//斜辺の長さを求める　

	if (r1 + r2 > dist) {
		return true;//当たっている
	}
	return false;
}

////////////////////////////////////////////////////////////
//ファイル操作//////////////////////////////
void LoadTextFile(const char* filePath, char text[][200],int size0) {
	FILE* fp = fopen(filePath,"r");
	for (int i = 0; i < size0; i++) {
		fscanf(fp, "%s", text[i]);
	}
	fclose(fp);
}

////////////////////////////////////////////////////////////