#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n, k;
	string cmd;
	stack<int> s;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> k;
			s.push(k);
			continue;
		}
		if (cmd == "pop") {
			if (s.empty())
				cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
			continue;
		}
		if (cmd == "size") {
			cout << s.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << s.empty() << '\n';
			continue;
		}
		if (cmd == "top") {
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
			continue;
		}
	}
}