#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<int> p, l;
	vector<int> cmp;
	int demand, supply, bet, cnt = 0;
	cin >> n >> m;
	// 입력
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> v1;
		cin >> demand >> supply;
		p.push_back(demand);
		l.push_back(supply);
		for (int j = 0; j < demand; j++)
		{
			cin >> bet;
			v1.push_back(bet);
		}
		v.push_back(v1);
	}
	// 각 과목의 Li번째로 큰 마일리지
	vector<priority_queue<int, vector<int>, greater<>>> pq; // 최소힙
	for (int i = 0; i < n; i++)
	{
		priority_queue<int, vector<int>, greater<>> pq1;
		for (int j = 0; j < p[i]; j++)
		{
			if (pq1.size() < l[i])
				pq1.push(v[i][j]);
			else if (pq1.top() < v[i][j]) {
				pq1.pop();
				pq1.push(v[i][j]);
			}
		}
		pq.push_back(pq1);
	}
	// 신청한 사람 < 수강인원
	for (int i = 0; i < n; i++)
	{
		// m > 0이라는 조건 반드시 필요
		if (p[i] < l[i] && m > 0)
		{
			cnt++;
			m--;
		}
		else if (m > 0)
			cmp.push_back(pq[i].top());
	}// 신청한 사람 >= 수강인원
	sort(cmp.begin(), cmp.end(), greater<>());
	while (cmp.size() != 0)
	{
		if (m - cmp.back() >= 0)
		{
			m -= cmp.back();
			cmp.pop_back();
			cnt++;
		}
		else
			break;
	}
	// 출력
	cout << cnt;
	return 0;
}