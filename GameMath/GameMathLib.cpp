
#include "GameMathLib.h"


//�O�p�֐��n�̏���//////////////////////////////
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
////////////////////////////////////////////////////////////
//�����蔻��̏���//////////////////////////////
//�l�p�̓����蔻��
bool HitRect(int centerX, int centerY, int width, int height, int px, int py) {
	if (px < centerX - width / 2 && px < centerX + width / 2) {
		if (py < centerY - height / 2 && py < centerY + height / 2) {
			return true;//�������Ă���
		}
	}
	return false;
}
//�~�̓����蔻��
bool HitCircle(float posX1, float posY1, float r1, float posX2, float posY2, float r2) {

	float distX, distY;//x&y�̋���
	float dist;//�_���m�̎Εӂ̋���

	distX = posX1 - posX2;//���������߂�
	distY = posY1 - posY2;

	dist = sqrt(distX*distX + distY * distY);//�Εӂ̒��������߂�@

	if (r1 + r2 > dist) {
		return true;//�������Ă���
	}
	return false;
}

////////////////////////////////////////////////////////////
//�t�@�C������//////////////////////////////
void LoadTextFile(const char* filePath, char text[][200],int size0) {
	FILE* fp = fopen(filePath,"r");
	for (int i = 0; i < size0; i++) {
		fscanf(fp, "%s", text[i]);
	}
	fclose(fp);
}

////////////////////////////////////////////////////////////