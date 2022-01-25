#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
		cout << lower_bound(x_sort.begin(), x_sort.end(), x[i]) - x_sort.begin() << ' ';
}