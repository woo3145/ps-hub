#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;

string S;
map<string, bool> cache;

void Solve() {
    for(int i = 0; i < S.length(); ++i){
        for(int j = 1; j <= S.length() - i; ++j){
            cache[S.substr(i, j)] = true;
        }
    }
    cout << cache.size();
}

void Input() {
    cin >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
