#include <iostream>
#include <stack>
#include <map>
#include <string>

using namespace std;

map<char, char> bracket;

bool isBalanced(string input) {
	stack<char> s;

	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '(': case '[': 
			s.push(input[i]);
			break;
		case ')': case']': 
			if (s.empty() || s.top() != bracket[input[i]])
				return false;
			s.pop();
			break;
		}
	}
	return s.empty();
}

int main() {
	string input;
	bracket[')'] = '(';
	bracket[']'] = '[';

	while (true) {
		getline(cin, input);
		if (input == ".")
			break;
	 cout << ((isBalanced(input)) ? "yes" : "no") << '\n';
	}
}