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
bool HitRect(int centerX, int centerY, int width, int height, int px, int py);

////////////////////////////////////////////////////////////
//�t�@�C������//////////////////////////////
//�t�@�C������1�s200�o�C�g���̃e�L�X�g��2�����z��ɓ���� �t�@�C���̓\�t�g��Shift-JIS�ɂ��邱�ƁAUTF-8�͕�����������
void LoadTextFile(const char* filePath,char text[][200],int size0);

////////////////////////////////////////////////////////////