
#include "GameMathLib.h"


namespace GameMath {
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
	//�����蔻��̏���2D//////////////////////////////
	//����Ɠ_�̓����蔻��
	bool HitBar(float center, float size, float point) {
		if (center - size / 2 < point && point < center + size / 2) {
			return true;
		}
		return false;
	}
	//�l�p�Ɠ_�̓����蔻��
	bool HitRect(Pos2 center, Pos2 size, Pos2 point) {
		bool tmp;
		for (int i = 0; i < 2; i++) {
			tmp = HitBar(center.p[i], size.p[i], point.p[i]);
			if (!tmp)
				break;
			if (i == 1)
				return true;
		}
		return false;
	}
	//�~���m�̓����蔻��(�~�Ɠ_���\
	bool HitCircle(Pos2 center1, float r1, Pos2 center2, float r2) {

		float distX, distY;//x&y�̋���
		float dist;//�_���m�̎Εӂ̋���

		distX = center1.p[0] - center2.p[0];//���������߂�
		distY = center1.p[1] - center2.p[1];

		dist = sqrt(distX*distX + distY * distY);//�Εӂ̒��������߂�@

		if (r1 + r2 > dist) {
			return true;//�������Ă���
		}
		return false;
	}
	//�O�p�Ɠ_�̓����蔻��
	Pos2 sub_vector(Pos2 pos0, Pos2 pos1)
	{
		Pos2 ret;
		ret.p[0] = pos0.p[0] - pos1.p[0];
		ret.p[1] = pos0.p[1] - pos1.p[1];
		return ret;
	}
	bool HitTriangle(Pos2 pos0, Pos2 pos1, Pos2 pos2, Pos2 point) {
		//����͊O�Ƃ݂Ȃ��܂��B

		Pos2 pos[6];
		pos[0] = sub_vector(pos1, pos0);
		pos[1] = sub_vector(point, pos1);

		pos[2] = sub_vector(pos2, pos1);
		pos[3] = sub_vector(point, pos2);

		pos[4] = sub_vector(pos0, pos2);
		pos[5] = sub_vector(point, pos0);

		//�O��    Z���������v�Z����΂悢�ł�
		double c1 = pos[0].p[0] *  pos[1].p[1] - pos[0].p[1] *  pos[1].p[0];
		double c2 = pos[2].p[0] *  pos[3].p[1] - pos[2].p[1] *  pos[3].p[0];
		double c3 = pos[4].p[0] *  pos[5].p[1] - pos[4].p[1] *  pos[5].p[0];

		if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) {
			//�O�p�`�̓����ɓ_������
			return true;
		}
		//�O�p�`�̊O���ɓ_������
		return false;
	}

	//�����蔻��̏����RD/////////////////////////////////////////////////
	//�l�p�Ɠ_�̓����蔻��
	bool HitRect3D(Pos3 center, Pos3 size, Pos3 point) {
		bool tmp;
		for (int i = 0; i < 3; i++) {
			tmp = HitBar(center.p[i], size.p[i], point.p[i]);
			if (!tmp)
				break;
			if (i == 2)
				return true;
		}
		return false;
	}
	//�~���m�̓����蔻��(�~�Ɠ_���\
	bool HitCircle3D(Pos3 center1, float r1, Pos3 center2, float r2) {
		Pos2 xy[2];
		xy[0].p[0] = center1.p[0];
		xy[0].p[1] = center1.p[1];

		xy[1].p[0] = center2.p[0];
		xy[1].p[1] = center2.p[1];

		Pos2 xz[2];
		xz[0].p[0] = center1.p[0];
		xz[0].p[1] = center1.p[2];

		xz[1].p[0] = center2.p[0];
		xz[1].p[1] = center2.p[2];

		bool tmp[2];
		tmp[0] = HitCircle(xy[0], r1, xy[1], r2);
		tmp[1] = HitCircle(xz[0], r1, xz[1], r2);

		if (tmp[0] && tmp[1]) {
			return true;
		}
		return false;
	}


	////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////

}