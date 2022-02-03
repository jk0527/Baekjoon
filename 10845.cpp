#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	string cmd;
	queue<int> q;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> k;
			q.push(k);
			continue;
		}
		if (cmd == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
			continue;
		}
		if (cmd == "size") {
			cout << q.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << q.empty() << '\n';
			continue;
		}
		if (cmd == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
			continue;
		}
		if (cmd == "back") {
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
			continue;
		}
	}
}