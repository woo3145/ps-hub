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

int T, N, M;
vector<int> coins;
vector<int> dp;

void Solve() {
    dp[0] = 1;

    for(auto& coin : coins){
        for(int i = coin; i <= M; ++i){
            dp[i] += dp[i - coin];
        }
    }
    
    cout << dp[M] << '\n';
}

void Input() {
    cin >> N;
    coins.clear();
    dp.clear();
    coins.resize(N);
    for(auto& c : coins){
        cin >> c;
    }
    cin >> M;

    dp.resize(M + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int i = 0; i < T; ++i){
        Input();
        Solve();
    }
    
    return 0;
}