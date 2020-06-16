
#include "GameMathLib.h"



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