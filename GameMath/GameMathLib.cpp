
#include "GameMathLib.h"



////���_�Ɗp�x�Ɣ��a�𑗂�ƈʒu���Ԃ��Ă��� �E���
void GetCirclePoint(float posX, float posY, float r, float  angle, float* px, float* py) {

	float rad = (double)angle / 180 * 3.1415;

	*px = posX + r * cos(rad);
	*py = posY + r * sin(rad);

}
//��ӂƍ�������Εӂ����o��
float GetHypotenuse(int x, int y) {
	return pow(pow(x, 2) + pow(y, 2), 0.5);
}

float GetCosWave(float angle) {
	return 	cos((double)angle / 180 * 3.1415);
}
float GetSinWave(float angle) {
	return 	sin((double)angle / 180 * 3.1415);
}