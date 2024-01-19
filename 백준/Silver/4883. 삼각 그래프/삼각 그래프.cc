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
int T;
int arr[3][100001];

void Solve() {
    vector<vector<int>> dp;
    dp.assign(3, vector<int>(N, 0)); 

    dp[0][0] = INT32_MAX;
    dp[1][0] = arr[1][0];
    dp[2][0] = arr[1][0] + arr[2][0];
    for(int i = 1; i < N; ++i){
        for(int j = 0; j < 3; ++j){
            dp[j][i] = dp[j][i-1];
            if(j < 2){
                dp[j][i] = std::min(dp[j][i], dp[j+1][i-1]);
            }
            if(0 < j){
                dp[j][i] = std::min(dp[j][i], dp[j-1][i-1]);
                dp[j][i] = std::min(dp[j][i], dp[j-1][i]);
            }   

            dp[j][i] += arr[j][i];
        }
    }

    cout << T << ". " << dp[1][N-1] << '\n';
}

void Input() {
    cin >> N;
    ++T;
    if(N == 0) return;
    for(int i = 0; i < N; ++i){
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
    }    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true){
        Input();
        if(N == 0) break;
        Solve();
    }
    
    return 0;
}
