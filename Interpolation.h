
#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include<vector>

using namespace std;

//���`��ԁi��O�����[�̌X����p���Đ��`�ɕ�O�j�ŋ��߂�Y��Ԃ��֐�
//inVectorX�͋��`�Z��������ł��邱�Ƃ�����

double LinearInterpolation(vector<double>& inVectorX,
						   vector<double>& inVectorY,
						   double inX);
#endif