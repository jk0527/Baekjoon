#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;

bool conquer(int size, int row, int col, int color) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[i + row][j + col] != color) 
				return false;
		}
	}
	return true;
}

vector<int> divide(int size, int row, int col) {
	vector<int> combine = { 0, 0 };

	if (conquer(size, row, col, paper[row][col])) {
		combine[paper[row][col]]++;
		return combine;
	}

	int sub_size = size / 2; 
	for (int i = 0; i <= sub_size; i += sub_size) {
		for (int j = 0; j <= sub_size; j += sub_size) {
			vector<int> sub_problem = divide(sub_size, row + i, col + j);
			combine[0] += sub_problem[0];
			combine[1] += sub_problem[1];
		}
	}
	return combine;
}

int main() {
	int n;

	cin >> n;
	paper.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	}

	vector<int> ans = divide(n, 0, 0);

	cout << ans[0] << '\n' << ans[1];
}