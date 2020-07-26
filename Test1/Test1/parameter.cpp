#include <iostream>
#include "parameter.h"
#include <math.h>

#define PI 3.1415926

using namespace std;

parameters::parameters() :fc(76.5e9), Bw(200e6), Fs(10e6), speedOfLight(3e8), phi(0), PRI(60e-6),
Nr(512), Na(128), N_tx(4), dd_r(0.5) {};//参数初始化

float parameters::dr() {
	return Fs * speedOfLight / 2 / Bw / Fs;
}
float parameters::dv() {
	return speedOfLight / 2 / fc / PRI / Na;
}

bool para1::windowingNr(vector<float> &blackman) {
	for (int i = 0;i < Nr;i++) {
		blackman.push_back(0.42 - 0.5 * cos(2 * PI * i / (Nr - 1)) + 0.08 * cos(4 * PI * i / (Nr - 1)));
	}
	return 1;
}


bool para1::windowingNa(vector<float>& blackman) {
	for (int i = 0;i < Na;i++) {
		blackman.push_back(0.42 - 0.5 * cos(2 * PI * i / (Na - 1)) + 0.08 * cos(4 * PI * i / (Na - 1)));
	}
	return 1;
}