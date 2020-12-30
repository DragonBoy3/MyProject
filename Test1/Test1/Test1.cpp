#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "musicfunc.h"
#include "parameter.h"
#include <vector>


using namespace std;

int main() {

	vector<vector<int>> maze(8, vector<int>(12, 0));
	for (vector<int>::size_type m = 0;m < maze.size();m++) {
		for (vector<int>::size_type n = 0;n < maze[m].size();n++) {
			maze[m][n] = m * maze[m].size() + n;
		}
	}

	cout << "local_merge+2" << endl;

	return 0;
}