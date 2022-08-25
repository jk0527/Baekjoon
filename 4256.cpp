#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder, inorder_idx;

void divide(int idx, int left, int right) {
	if (left > right)
		return;
	int root = preorder[idx];
	int root_idx = inorder_idx[root];

	divide(idx + 1, left, root_idx - 1);
	divide(idx + (root_idx - left) + 1, root_idx + 1, right);
	cout << root << ' ';
}

int main() {
	int t, n, num;

	cin >> t;
	while (t--) {
		cin >> n;
		preorder.assign(n, 0);
		inorder_idx.assign(n + 1, 0);

		for (int i = 0; i < n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++) {
			cin >> num;
			inorder_idx[num] = i;
		}

		divide(0, 0, n - 1);
		cout << '\n';
	}
}
