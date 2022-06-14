#include <iostream>

using namespace std;

int constructor(int n) {
	for (int i = 1; i < n; i++) {
		int k = i; 
		int sum = i; 
		while (k > 0) { 
			sum += (k % 10);
			k /= 10;
		}
		if (sum == n) 
			return i;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	cout << constructor(n) << '\n';
	return 0;
}