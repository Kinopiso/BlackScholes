
#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include<vector>

using namespace std;

//線形補間（補外も両端の傾きを用いて線形に補外）で求めたYを返す関数
//inVectorXは狭義短調増加列であることを仮定

double LinearInterpolation(vector<double>& inVectorX,
						   vector<double>& inVectorY,
						   double inX);
#endif