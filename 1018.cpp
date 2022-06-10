#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 64;

int chessChange(int row, int col, vector<vector<char>>& board) {
	int b_cnt = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B')
				b_cnt++;
			else if ((i + j) % 2 && board[row + i][col + j] != 'W')
				b_cnt++;
		}
	}
	if (b_cnt > SIZE / 2)
		return SIZE - b_cnt;
	return b_cnt;
}


int main() {
	int n, m;
	int ans = SIZE + 1; 

	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m)); 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt = chessChange(i, j, board); 
			ans = min(ans, cnt); 
		}
	}

	cout << ans << '\n';
	return 0;
}