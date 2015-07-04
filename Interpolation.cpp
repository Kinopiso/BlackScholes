#include"Interpolation.h"
#include<vector>
#include<iostream>

using namespace std;
//線形補間（補外も両端の傾きを用いて線形に補外）で求めたYを返す関数
//inVectorXは狭義短調増加列であることを仮定
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

	//inVectorX,inVectorYの[-1],[size]を呼び出さないために,例外処理
	if(i == 0){
		i++;
	}else if(i >= inVectorX.size()){
		i = inVectorX.size() - 1;
	}

	lReturn = inVectorY[i-1] + 
				(inX - inVectorX[i-1]) * (inVectorY[i] - inVectorY[i-1]) / (inVectorX[i] - inVectorX[i-1]);

	return(lReturn);

}