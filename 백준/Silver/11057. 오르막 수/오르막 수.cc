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
int dp[10][1001];

void Solve() {
    for(int i = 0; i < 10; ++i){
        dp[i][1] = 1;
    }

    for(int i = 2; i <= N; ++i){
        for(int j = 0; j < 10; ++j){
            for(int k = 0; k <= j; ++k){
                dp[j][i] += dp[k][i - 1];
                dp[j][i] %= 10007;
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < 10; ++i){
        answer += dp[i][N];
    }
    cout << answer % 10007;
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
