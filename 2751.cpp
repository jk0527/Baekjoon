#include <iostream>
#include <vector>

using namespace std;

vector <int> arr, sorted;

void merge(int left, int middle, int right)
{
	int p1 = left, p2 = middle + 1, p3 = left;
	while (p1 <= middle && p2 <= right)
	{
		if (arr[p1] < arr[p2])
			sorted[p3++] = arr[p1++];
		else
			sorted[p3++] = arr[p2++];
	}
	while (p1 <= middle)
		sorted[p3++] = arr[p1++];
	while (p2 <= right)
		sorted[p3++] = arr[p2++];
	for (int i = left; i <= right; i++)
		arr[i] = sorted[i];
}

void mergeSort(int left, int right) 
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, middle, right);
	}
}
int main() 
{
	int n, x;
	cin >> n;

	sorted.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	mergeSort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
}