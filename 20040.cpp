#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

// Find 연산
int find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

// Union 연산
bool unionInput(int x, int y) {
	int xp = find(x);
	int yp = find(y);

	if (xp == yp) {
		return false;
	}
	if (parent[xp] < parent[yp]) {
		parent[xp] += parent[yp];
		parent[yp] = xp;
	}
	else {
		parent[yp] += parent[xp];
		parent[xp] = yp;
	}
	return true;
}

int main()
{
	int n, m, p1, p2, end = 0;
	cin >> n >> m;
	// 입력
	parent.assign(n, -1);
	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;

		// 연산 & 출력
		if (!unionInput(p1, p2)) { // 사이클 생성
			end = i + 1;
			break;
		}
	}
	cout << end << '\n'; // 사이클 생성 X
	return 0;
}
