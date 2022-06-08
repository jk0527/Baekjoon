#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 5000000;

vector<int> isPrime() {
	vector<int> prime(SIZE+1, 0);
	for (int i = 2; i <= SIZE; i++)
		prime[i] = i;

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i] == i) { 
			for (int j = i * i; j <= SIZE; j += i) { 
				if (prime[j] == j) { 
					prime[j] = i;
				}
			}
		}
	}

	return prime;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n;

	vector<int> prime = isPrime();

	while (n--) {
		cin >> k;
		while (k > 1) {
			cout << prime[k] << ' ';
			k = k / prime[k];
		}
		cout << '\n';
	}
	return 0;
}