#include <iostream>
#include <map>
#include <vector>

using namespace std;

void pass(map<string, int>in, vector<int>out)
{
	int tmp, ans = 0;
	for (int i = 0; i < in.size(); i++)
	{
		tmp = out[i];
		for (int j = i + 1; j < in.size(); j++)
		{
			if (tmp > out[j])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
}

int main()
{
	int n;
	string car;
	map<string, int>order_in;
	vector<int>order_out;

	cin >> n;

	// 들어가는 차
	for (int i = 0; i < n; i++)
	{
		cin >> car;
		order_in[car] = i;
	}

	// 나가는 차
	for (int i = 0; i < n; i++)
	{
		cin >> car;
		order_out.push_back(order_in[car]);
	}
	pass(order_in, order_out);
}