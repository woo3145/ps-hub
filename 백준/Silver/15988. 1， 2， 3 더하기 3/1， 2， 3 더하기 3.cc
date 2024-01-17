#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;

int T;
vector<int> arr; 
long long dp[1000001];
long long MOD = 1000000009;

void Solve() {
    dp[1] = 1;
    dp[2] = 2; // 1 1, 2
    dp[3] = 4; // 1 1 1, 1 2, 2 1, 3
    dp[4] = 7; // 1 1 1 1, 1 1 2, 1 2 1, 2 1 1, 2 2, 1 3, 3 1

    for(int i = 5; i < 1000001; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        dp[i] %= MOD;
    }

    for(auto& a : arr){
        cout << dp[a] << '\n';
    }
}

void Input() {
    cin >> T;
    arr.resize(T);
    for(auto& a : arr) {
        cin >> a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}