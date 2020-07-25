#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>

using namespace std;


int func(int N) {
	if (N < 5) {
		return 0;
	}
	vector<int> v(N,0);
	v[4] = 1;
	for (int i = 5;i < N;i++) {
		v[i] = (v[i - 1] + v[i - 5]) % 998244353;
	}


	return v[N-1];
}
