#include <iostream>

using namespace std;
typedef long long ll;

ll divide(int a, int b, int c) {
	if (b == 1)
		return a % c;
	if (b % 2 == 0) {
		ll sub_problem = divide(a, b / 2, c);
		return (sub_problem * sub_problem) % c;
	}
	return (a * divide(a, b - 1, c)) % c; 
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << divide(a, b, c);
}