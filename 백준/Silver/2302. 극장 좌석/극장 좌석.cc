#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, M;
vector<int> fixed; 
int dp[41];

void Solve() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int answer = 1;
    int left = 1;
    for(int i = 0; i < M; ++i){
        int right = fixed[i];

        answer *= dp[right - left];
        left = right + 1;
    }
    answer *= dp[N - left + 1];

    cout << answer;
}

void Input() {
    cin >> N >> M;
    fixed.resize(M);
    for(auto& a : fixed){
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