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


string S;
vector<int> dp;
const int MOD = 1000000;

void Solve() {
    if(S.length() == 1 && S[0] == '0') {
        cout << 0;
        return;
    }
    dp[0] = 1;

    for(int i = 1; i <= S.length(); ++i){
        if(S[i - 1] != '0') dp[i] = dp[i - 1];
        
        if(i == 1) continue;

        int cur = (S[i-2] - '0') * 10 + S[i-1] - '0';

        if(10 <= cur && cur <= 26){
            dp[i] += dp[i-2];
        }

        dp[i] %= MOD;
    }

    cout << dp[S.length()];
}

void Input() {
    cin >> S;
    dp.resize(S.length() + 1, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
