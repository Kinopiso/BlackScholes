
#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H
#include"Interpolation.h"
#include<string>
#include<vector>
#include<string>

const string CALL = "C";
const string PUT = "P";

//BlackScholesモデルによるオプション価格を返す関数
double BlackScholes(double inSpot,
					double inStrike,
					double inSigma,
					double inMaturity,
					string inCallPut,
					vector<double>& inIRRate,
					vector<double>& inIRTime);

//標準正規分布の分布関数を返す．
//やり方は，0から引数の絶対値まで密度関数を台形積分して,
//引数が正だったら結果に0.5を足し，引数が負だったら0.5から結果を引いて求める．
//調整が面倒くさいので,一旦刻み幅は刻み数を固定して実行．
double NormalDistributionFunction(double dblX);

//標準正規分布の密度関数を返す．
double NormalDensityFunction(double dblX);

#endif