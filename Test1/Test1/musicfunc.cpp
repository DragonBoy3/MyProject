#include <iostream>
#include <math.h>
#include <vector>
#include "musicfunc.h"
#include "parameter.h"
#define PI 3.1415926
using namespace std;

void sigGeneration(float R0,float v, vector<vector<long double>>&sigSpace) {
	parameters* p = new para1;
	long double Tp = (*p).Nr / (*p).Fs;
	long double kr = p->Bw / Tp;
	long double dr = (*p).dr();
	long double dv = (*p).dv();
	long double c = (*p).speedOfLight;
	long double R,tr;
	vector<long double> sigQuickTime((*p).Nr, 0);
	for (int na = 0;na < (*p).Na;na++) {
		R = R0 + v * na * (*p).PRI;
		for (int nr = 0;nr < (*p).Nr;nr++) {
			tr = (nr - (*p).Nr / 2) / (*p).Fs;
			sigQuickTime[nr] = (cos(2 * PI * (tr * (kr * 2 * R / c - 4 * v * kr * R / c / c + 2 * v * (*p).fc / c)
				+ tr * tr * (2 * v * kr / c - 2 * v * v * kr / c / c) + ((*p).fc * (*p).fc * R / c - kr * 2 * R *
					R / c / c - (*p).phi))));
		}
		sigSpace.push_back(sigQuickTime);
		sigQuickTime.clear();
	}
}


void fft3(vector<float>& blackmanNr, vector<float>& blackmanNa, vector<vector<vector<long double>>>& sigSpace) {
	parameters* p = new para1;

}

