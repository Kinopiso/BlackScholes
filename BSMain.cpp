//Vectorを使ったBS式の実装

#include"Interpolation.h"
#include<iostream>
#include<vector>

using namespace std;

//Interpolationテスト用のメイン関数
int main(void)
{
	vector<double> lIRRate(2);
	vector<double> lIRTime(2);
	double lTime;
	double tmp;

	lIRRate[0] = 1.0;
	lIRRate[1] = 2.0;

	lIRTime[0] = 0.0;
	lIRTime[1] = 1.0;

	lTime = 0.5;
	tmp = LinearInterpolation(lIRTime, lIRRate, lTime);
	
	cout << tmp <<"\n";
	cin >> tmp;

	return(0);
}