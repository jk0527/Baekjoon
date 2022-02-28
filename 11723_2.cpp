#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set <int> s;
	int M, n;
	string cmd;
	cin >> M; cout.tie(NULL);
	while (M--)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			cin >> n;
			s.insert(n);
		}
		if (cmd == "remove")
		{
			cin >> n;
			if(s.find(n) != s.end())
				s.erase(s.find(n));
		}
		if (cmd == "check")
		{
			cin >> n;
			if (s.find(n) != s.end())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		if (cmd == "toggle")
		{
			cin >> n;
			if (s.find(n) != s.end())
				s.erase(s.find(n));
			else
				s.insert(n);
		}
		if (cmd == "all")
		{
			s.clear();
			s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20 };
		}
		if (cmd == "empty")
			s.clear ();
	}
	return 0;
}