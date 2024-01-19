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
int dp[100001];

void Solve() {
    
    for(int i = 1; i <= N; ++i){
        dp[i] = i;

        for(int j = 1; j * j <= i; ++j){
            dp[i] = std::min(dp[i], dp[i - j*j] + 1);
        }
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
