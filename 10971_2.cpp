// Traveling Salesman problem (TSP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;

int n, cost, min_cost = 10000000;
bool check_visited[SIZE + 1];
vector<vector<int>> w;

void backtracking(int cnt, int start, int next)
{
	if (cnt == n && start == next) {
		min_cost = min(min_cost, cost);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!check_visited[i] && w[next][i] != 0) {
			check_visited[i] = true;
			cost += w[next][i];
			cnt++;
			//cout << "cnt:" << cnt << " start:" << start << " i:" << i << " next:" << next << " cost:" << cost << '\n';
			//for (int t = 0; t < n; t++)
			//	cout << check_visited[t];
			//cout << '\n';
			backtracking(cnt, start, i);
			check_visited[i] = false;
			cost -= w[next][i];
			cnt--;
		}
	}
}

int main()
{
	cin >> n;
	w.assign(n, vector<int>(n, 0));
	// 입력
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	// 시작 도시마다 비용 계산
	for (int i = 0; i < n; i++)
		backtracking(0, i, i);
	// 출력
	cout << min_cost << '\n';
	return 0;
}