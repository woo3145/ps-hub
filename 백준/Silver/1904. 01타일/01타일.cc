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

int N;
int dp[1000001];

void Solve() {
    dp[1] = 1; // 1
    dp[2] = 2; // 11, 00

    for(int i = 3; i <= N; ++i){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 15746;
    }

    cout << dp[N];
}

void Input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
