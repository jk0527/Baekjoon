#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 100;
struct curve {
	int x, y, d, g;
};

// 방향: 우(0), 상(1), 좌(2), 하(3)
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

// 1x1인 정사각형의 갯수를 계산
int cntSquares(vector<vector<bool>> plane) {
	int ans = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1])
				ans++;
	return ans;
}

// 평면에 드래곤 커브를 표시
void drawDragonCurves(int n, vector<vector<bool>>& plane, vector<curve> curve) {
	for (int i = 0; i < n; i++) { // n개의 드래곤 커브 그리기
		vector<int> direct; // 방향 저장
		int x = curve[i].x, y = curve[i].y, d = curve[i].d, g = curve[i].g; // 0 세대
		plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // 평면에 표시
		x += dx[d];
		y += dy[d];
		direct.push_back(d);
		while (g--) { // 1 ~ n 세대
			int size_d = direct.size();
			for (int j = size_d - 1; j >= 0; j--) { // 방향 계산
				int next_d = (direct[j] + 1) % 4;
				x += dx[next_d];
				y += dy[next_d];
				plane[y][x] = true; // 평면에 표시
				direct.push_back(next_d);
			}

		}
	}
}

int main()
{
	int n;
	vector<curve> dragon_curves; 
	vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); 
	// 입력
	cin >> n;
	dragon_curves.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> dragon_curves[i].x >> dragon_curves[i].y >> dragon_curves[i].d >> dragon_curves[i].g;
	}
	// 연산 & 출력
	drawDragonCurves(n, plane, dragon_curves);
	cout << cntSquares(plane) << '\n';
	return 0;
}
