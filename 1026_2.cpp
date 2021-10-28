#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n, s = 0;
	vector<int> a, b;
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	while (!b.empty())
	{
		int min = 101, idx = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (min > b[i])
			{
				min = b[i];
				idx = i;
			}
		}
		s += a[a.size() - 1]* b[idx];
		a.pop_back();
		b.erase(b.begin() + idx);
	}
	cout << s;
}