#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE]; 
bool check_left[SIZE * 2]; 
bool check_right[SIZE * 2]; 

void backtracking(int cnt) {
	if (cnt == n) { 
		ans++; 
		return;
	}
	for (int i = 0; i < n; i++) { 
		if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) {
			check_col[i] = true;
			check_left[cnt + i] = true;
			check_right[cnt - i + n] = true;
			backtracking(cnt + 1); 
			check_col[i] = false;
			check_left[cnt + i] = false;
			check_right[cnt - i + n] = false;
		}
	}
}

int main() {
	cin >> n;

	backtracking(0);

	cout << ans << '\n';

	return 0;
}