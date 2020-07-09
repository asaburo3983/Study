#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define AngleToRadian(angle) (angle/180.0*3.14)
#define RadianToAngle(radian) (radian*180.0/3.14)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//�O�p�֐�//////////////////////////////
////���_�Ɗp�x�Ɣ��a�𑗂�ƈʒu���Ԃ��Ă��� �E���
void GetCirclePoint(float posX, float posY, float r, float  angle, float* px, float* py);
//��ӂƍ�������Εӂ����o��
float GetHypotenuse(int x, int y);
float GetCosWave(float angle);
float GetSinWave(float angle);
////////////////////////////////////////////////////////////
//�����蔻��//////////////////////////////
//���S�_��`�掲�Ƃ���l�p�摜�̓����蔻��
bool HitRect(int centerX, int centerY, int width, int height, int px, int py);//��`
bool HitCircle(float posX1, float posY1, float r1, float posX2, float posY2, float r2);//�~
////////////////////////////////////////////////////////////
//�t�@�C������//////////////////////////////
//�t�@�C������1�s200�o�C�g���̃e�L�X�g��2�����z��ɓ���� �t�@�C���̓\�t�g��Shift-JIS�ɂ��邱�ƁAUTF-8�͕�����������
void LoadTextFile(const char* filePath,char text[][200],int size0);

////////////////////////////////////////////////////////////

//�l�p����̃N���X
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
