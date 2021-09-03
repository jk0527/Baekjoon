#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(int n, vector<int> &arr)
{
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = false;
			}
		}
		if (flag)
			return;
	}
}

int main()
{
	vector<int> arr;
	int n;
	cin >> n;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bubbleSort(n, arr);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}