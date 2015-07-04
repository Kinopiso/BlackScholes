
#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H
#include"Interpolation.h"
#include<vector>


//BlackScholesモデルによるオプション価格を返す関数
double BlackScholes(double inSpot,
					double inStrike,
					double inSigma,
					double inMaturity,
					char inCallPut,
					vector& inIRRate,
					vector& inIRTime)

#endif