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

int T, N;
vector<int> arr[2]; 
vector<int> dp[2];

void Solve() {
    dp[0][1] = arr[0][1];
    dp[1][1] = arr[1][1];

    for(int i = 2; i <= N; ++i){
        dp[0][i] = std::max(dp[0][i-1], dp[1][i-1] + arr[0][i]);
        dp[1][i] = std::max(dp[1][i-1], dp[0][i-1] + arr[1][i]);
    }

    cout << std::max(dp[0][N], dp[1][N]) << '\n';
}

void Input() {
    cin >> N;
    arr[0].clear();
    arr[1].clear();
    dp[0].clear();
    dp[1].clear();

    arr[0].resize(N + 1, 0);
    arr[1].resize(N + 1, 0);
    dp[0].resize(N + 1, 0);
    dp[1].resize(N + 1, 0);
    
    for(int i = 1; i <= N; ++i) cin >> arr[0][i];
    for(int i = 1; i <= N; ++i) cin >> arr[1][i];
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
