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
const int MOD = 1000000000;

void Solve() {
    dp[0] = 0; 
    dp[1] = 1; 

    int n = std::abs(N);

    for(int i = 2; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }

    if(0 == N) {
        cout << 0 << '\n';
    }else if (0 < N){
        cout << 1 << '\n';
    }else if(n % 2 == 0) {
        cout << -1 << '\n';
    }else {
        cout << 1 << '\n';
    }
    cout << dp[n];
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
