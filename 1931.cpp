#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci& a, const ci& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first; 
}

int maxMeeting(int n, vector<ci> meeting) {
	int end = meeting[0].second; 
	int cnt = 1; 
	for (int i = 1; i < n; i++) {
		if (end <= meeting[i].first) { 
			cnt++;
			end = meeting[i].second; 
		}
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	vector<ci> meeting(n, ci(0, 0));
	for (int i = 0; i < n; i++)
		cin >> meeting[i].first >> meeting[i].second;
	sort(meeting.begin(), meeting.end(), cmp);
	cout << maxMeeting(n, meeting);

	return 0;
}