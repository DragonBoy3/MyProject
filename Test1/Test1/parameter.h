#ifndef _parameter_H_
#define _parameter_H_
#include <vector>
using namespace std;

class parameters {
public:
	int fc;//发射信号频率
	int Bw;//bandwidth
	int Fs;//sample frequency;
	int speedOfLight;//光速c
	int phi;//发射信号初始相位
	int PRI;//脉冲重复频率
	int Nr;//距离向（快时间）采样点数
	int Na;//方位向（慢时间）采样点数
	int N_tx;//发射天线数量
	int dd_r; //发射天线间隔（波长倍数）

public:
	parameters();//参数初始化
	virtual bool windowingNr(vector<float>&windowfunc) = 0;//窗函数接口Nr
	virtual bool windowingNa(vector<float>&windowfunc) = 0;//窗函数接口Na
	float dr();
	float dv();
};


class para1 :public parameters {
public:
	bool windowingNr(vector<float>&windowfunc);
	bool windowingNa(vector<float>&windowfunc);
};

#endif
