#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N;
vector<int> dp;

void Solve() {
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for(int i = 5; i <= N; ++i){
        if(dp[i - 1] && dp[i-3] && dp[i-4]) {
            dp[i] = 0;
            continue;
        };
        dp[i] = 1;
    }

    if(dp[N]){
        cout << "SK";
    }else{
        cout << "CY";
    }
}

void Input() {
    cin >> N;
    dp.resize(N + 1, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
