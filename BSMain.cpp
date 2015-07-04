//Vectorを使ったBS式の実装

#include"Interpolation.h"
#include"BlackScholes.h"
#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	double lSpot = 100;
	double lStrike = 100;
	double lMaturity = 1.2;
	double lSigma = 0.1;
	vector<double> lIRRate(3);
	vector<double> lIRTime(3);
	lIRRate[0] = 0.01;
	lIRRate[1] = 0.02;
	lIRRate[2] = 0.03;
	lIRTime[0] = 0.0;
	lIRTime[1] = 1.0;
	lIRTime[2] = 2.0;
	
	double tmp;
	

	tmp = BlackScholes(lSpot,
					   lStrike,
					   lSigma,
					   lMaturity,
					   CALL,
					   lIRRate,
					   lIRTime);
	cout << tmp << "\n"; 

	tmp = BlackScholes(lSpot,
					   lStrike,
					   lSigma,
					   lMaturity,
					   PUT,
					   lIRRate,
					   lIRTime);
	
	cout << tmp << "\n";

	cin >> tmp;
	return(0);
}



/*//正規分布の分布関数テスト
//小数点以下4～5乗くらいの精度はありそうなので，とりあえずおｋ
int main(void)
{
	double lDblX;
	double tmp;

	//上側2.5%点
	lDblX = 1.96;
	tmp = NormalDistributionFunction(lDblX);
	cout << tmp << "\n";
	tmp = NormalDistributionFunction(-lDblX);
	cout << tmp << "\n";
	tmp = NormalDistributionFunction(0.0);
	cout << tmp << "\n";
	cin >> tmp;
	return(0);
}*/


/*//Interpolationテスト用のメイン関数
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
	
	lTime = -0.5;
	tmp = LinearInterpolation(lIRTime, lIRRate, lTime);
	cout << tmp <<"\n";

	lTime = 1.5;
	tmp = LinearInterpolation(lIRTime, lIRRate, lTime);
	cout << tmp <<"\n";

	cin >> tmp;

	return(0);
}*/