#include <iostream>
#include <algorithm>

using namespace std;

int gcdRecursion(int a, int b) {
	if (b == 0) 
		return a;
	return gcdRecursion(b, a % b);
}

int main() {
	int a, b;

	cin >> a >> b;

	int g = gcdRecursion(max(a, b), min(a, b)); 
	int l = (a * b) / g;

	cout << g << '\n' << l << '\n';

	return 0;
}