#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> num(n, false); 

    for (int i = 0; i < m; i++) 
        num[i] = true;

    do {
        for (int i = 0; i < n; i++) {
            if (num[i]) 
                cout << i + 1 << ' ';
        }
        cout << '\n';
    } while (prev_permutation(num.begin(), num.end()));

    return 0;
}