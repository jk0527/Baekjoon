#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int w, v;
};

int knapsack_2(int n, int k, vector<info>& product) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < product[i].w; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = product[i].w; j <= k; j++)
			dp[i][j] = max(dp[i - 1][j - product[i].w] + product[i].v, dp[i - 1][j]);
		/* 과정
		for (int p = 0; p < n + 1; p++)
		{
			for (int j = 0; j < k + 1; j++)
				cout << dp[p][j];
			cout << '\n';
		}
		*/
	}
	return dp[n][k];
}

int knapsack_1(int n, int k, vector<info>& product) {
	vector<int> dp(k + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= product[i].w; j--)
			dp[j] = max(dp[j - product[i].w] + product[i].v, dp[j]);
		/*
		for (int j = 0; j < k + 1; j++)
			cout << dp[j];
		cout << '\n';
		*/
	}
	return dp[k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<info> product(n + 1, { 0,0 });
	for (int i = 1; i <= n; i++)
		cin >> product[i].w >> product[i].v;
	cout << knapsack_1(n, k, product) << '\n';
	return 0;
}
