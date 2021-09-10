#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
	string name;
	int korean, english, math;
};

bool cmp(const student& s1, const student& s2)
{
	if (s1.korean != s2.korean)
		return s1.korean > s2.korean;
	else
	{
		if (s1.english != s2.english)
			return s1.english < s2.english;
		else
		{
			if (s1.math != s2.math)
				return s1.math > s2.math;
			return s1.name < s2.name;
		}
	}
}

int main()
{
	int n;
	vector<student> myclass;
	cin >> n;
	myclass.assign(n, {});
	for (int i = 0; i < n; i++)
		cin >> myclass[i].name >> myclass[i].korean >> myclass[i].english >> myclass[i].math;

	sort(myclass.begin(), myclass.end(), cmp);

	for (int i = 0; i < myclass.size(); i++)
		cout << myclass[i].name << '\n';
}