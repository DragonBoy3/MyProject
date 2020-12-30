#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>


using namespace std;

int main() {

	vector<vector<int>> maze(8, vector<int>(12, 0));
	for (vector<int>::size_type m = 0;m < maze.size();m++) {
		for (vector<int>::size_type n = 0;n < maze[m].size();n++) {
			maze[m][n] = m * maze[m].size() + n;
		}
	}

	cout << "result." << endl;

	cout << "conflict_test" << endl;

	cout << "conflict_line2" << endl;
	cout << "conflict_line" << endl;

	cout << "conflict_line3" << endl;

	return 0;
}