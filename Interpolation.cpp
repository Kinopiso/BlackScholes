#include"Interpolation.h"
#include<vector>
#include<iostream>

using namespace std;
//���`��ԁi��O�����[�̌X����p���Đ��`�ɕ�O�j�ŋ��߂�Y��Ԃ��֐�
//inVectorX�͋��`�Z��������ł��邱�Ƃ�����
double LinearInterpolation(vector<double>& inVectorX,
						   vector<double>& inVectorY,
						   double inX)
{
	unsigned long i;
	double lReturn;

	i = 0;
	
	for(i = 0;i < inVectorX.size(); i++){
		if(inX <= inVectorX[i]){
			break;
		}
		i++;
	}

	//inVectorX,inVectorY��[-1],[size]���Ăяo���Ȃ����߂�,��O����
	if(i == 0){
		i++;
	}else if(i >= inVectorX.size()){
		i = inVectorX.size() - 1;
	}

	lReturn = inVectorY[i-1] + 
				(inX - inVectorX[i-1]) * (inVectorY[i] - inVectorY[i-1]) / (inVectorX[i] - inVectorX[i-1]);

	return(lReturn);

}