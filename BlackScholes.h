
#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H
#include"Interpolation.h"
#include<string>
#include<vector>
#include<string>

const string CALL = "C";
const string PUT = "P";

//BlackScholes���f���ɂ��I�v�V�������i��Ԃ��֐�
double BlackScholes(double inSpot,
					double inStrike,
					double inSigma,
					double inMaturity,
					string inCallPut,
					vector<double>& inIRRate,
					vector<double>& inIRTime);

//�W�����K���z�̕��z�֐���Ԃ��D
//�����́C0��������̐�Βl�܂Ŗ��x�֐����`�ϕ�����,
//���������������猋�ʂ�0.5�𑫂��C����������������0.5���猋�ʂ������ċ��߂�D
//�������ʓ|�������̂�,��U���ݕ��͍��ݐ����Œ肵�Ď��s�D
double NormalDistributionFunction(double dblX);

//�W�����K���z�̖��x�֐���Ԃ��D
double NormalDensityFunction(double dblX);

#endif