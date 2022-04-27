#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int LINE = 6;

int main()
{
	// 입력
	int N, P, L, note, cnt = 0;
	cin >> N >> P;

	stack <int> moves[LINE];
	while(N--)
	{
		cin >> L >> note;
		// pop: 그 줄에 무언가 누르고 있고 누른 음의 프렛이 더 낮을 때
		while (!moves[L - 1].empty() && moves[L - 1].top() > note)
		{
			moves[L - 1].pop();
			cnt++;
		}
		// push: 그 줄에 아무것도 누르고 있지 않거나 음의 프렛이 더 높을 때
		if (moves[L - 1].empty() || moves[L - 1].top() < note)
		{
			moves[L - 1].push(note);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}