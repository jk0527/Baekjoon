#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> x, int v)
{
	int s = 0, e = x.size() - 1, mid = 0;
	while(s <= e)
	{
		mid = (s + e) / 2;
		if (v == x[mid])
			return mid;
		else if (v < x[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	vector<int> x, x_sort;
	cin >> n;
	x.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	x_sort = x;
	sort(x_sort.begin(), x_sort.end());
	x_sort.resize(unique(x_sort.begin(), x_sort.end())-x_sort.begin());
	for (int i = 0; i < n; i++)
		cout << search(x_sort, x[i]) << ' ';
}