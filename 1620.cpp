#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void findMonster(map<string, int> name, map<int, string> number, vector<string> unknown)
{
	for (auto iter = unknown.begin(); iter != unknown.end(); iter++)
	{
		if (isdigit((*iter)[0]))
			cout<< number[stoi(*iter)] <<'\n';
		else
			cout << name[*iter] << '\n';
	}
}

int main()
{
	int n, m;
	string monster;
	cin >> n >> m;
	map<string, int> name;
	map<int, string> number;
	vector<string> unknown;
	unknown.assign(m, "");

	for (int i = 1; i <= n; i++)
	{
		cin >> monster;
		name[monster] = i;
		number[i] = monster;
	}
	
	for (int i = 0; i < m; i++)
		cin >> unknown[i];

	findMonster(name, number, unknown);
}