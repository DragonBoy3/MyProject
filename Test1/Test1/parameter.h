#ifndef _parameter_H_
#define _parameter_H_
#include <vector>
using namespace std;

class parameters {
public:
	int fc;//�����ź�Ƶ��
	int Bw;//bandwidth
	int Fs;//sample frequency;
	int speedOfLight;//����c
	int phi;//�����źų�ʼ��λ
	int PRI;//�����ظ�Ƶ��
	int Nr;//�����򣨿�ʱ�䣩��������
	int Na;//��λ����ʱ�䣩��������
	int N_tx;//������������
	int dd_r; //�������߼��������������

public:
	parameters();//������ʼ��
	virtual bool windowingNr(vector<float>&windowfunc) = 0;//�������ӿ�Nr
	virtual bool windowingNa(vector<float>&windowfunc) = 0;//�������ӿ�Na
	float dr();
	float dv();
};


class para1 :public parameters {
public:
	bool windowingNr(vector<float>&windowfunc);
	bool windowingNa(vector<float>&windowfunc);
};

#endif
