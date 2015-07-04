#include"BlackScholes.h"
#include"Interpolation.h"
#include<string>
#include<vector>
#include<cmath>

const double PI = 3.14159;
/*
const string CALL = "C";
const string PUT = "P";
*/

double BlackScholes(double inSpot,
					double inStrike,
					double inSigma,
					double inMaturity,
					string inCallPut,
					vector<double>& inIRRate,
					vector<double>& inIRTime){
	
	double lReturn;
	double d1;
	double d2;
	double lSpotRate;
	double lDF;

	lSpotRate = LinearInterpolation(inIRTime, inIRRate, inMaturity);
	
	d1 = (log(inSpot / inStrike) 
			+ (lSpotRate + inSigma * inSigma / 2.0) * inMaturity)
		 / (inSigma * sqrt(inMaturity));
	
	d2 = d1 - inSigma * sqrt(inMaturity);
	
	lDF = exp(-lSpotRate * inMaturity);

	if(inCallPut == CALL){
		lReturn = inSpot * NormalDistributionFunction(d1) 
					- lDF * inStrike * NormalDistributionFunction(d2);
	}else if(inCallPut == PUT){
		lReturn = - inSpot * NormalDistributionFunction(-d1)
					+ lDF * inStrike * NormalDistributionFunction(-d2);
	}

	return(lReturn);

}

//標準正規分布の分布関数を返す．
//やり方は，0から引数の絶対値まで密度関数を台形積分して,
//引数が正だったら結果に0.5を足し，引数が負だったら0.5から結果を引いて求める．
//調整が面倒くさいので,一旦刻み幅は刻み数を固定して実行．
double NormalDistributionFunction(double dblX){
	double lRunningSum;
	double lReturn;
	double lLeftX;
	double lRightX;
	double lLeftY;
	double lRightY;
	unsigned long lNum = 10000;
	unsigned long i;
	
	lLeftX = 0.0;
	lLeftY = NormalDensityFunction(lLeftX);
	lRunningSum = 0.0;

	for(i = 0; i < lNum; i++){
		lRightX = static_cast<double>(i) * (abs(dblX) / static_cast<double>(lNum));
		lRightY = NormalDensityFunction(lRightX);
		lRunningSum = lRunningSum + (lLeftY + lRightY) * (lRightX - lLeftX) / 2.0;
		lLeftX = lRightX;
		lLeftY = lRightY;
	}

	if(dblX > 0){
		lReturn = lRunningSum + 0.5;
	}else{
		lReturn = 0.5 - lRunningSum;
	}
	return(lReturn);
}

//標準正規分布の密度関数を返す．
double NormalDensityFunction(double dblX){
	double lReturn;
	lReturn = exp(-dblX * dblX / 2) / sqrt(2 * PI);
	return(lReturn);
}
