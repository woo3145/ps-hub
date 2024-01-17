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

int T, W;
vector<int> arr; 
int dp[31][1001];

void Solve() {
    if(arr[0] == 1){
        dp[0][0] = 1;
    }else{
        dp[1][0] = 1;
    }

    for(int t = 1; t < T; ++t){
        for(int w = 0; w <= W; ++w){
            if((arr[t] == 1 && w % 2 == 0) || (arr[t] == 2 && w % 2 == 1)) {
                dp[w][t] = dp[w][t-1] + 1;
                if(0 < w) dp[w][t] = std::max(dp[w][t], dp[w-1][t-1] + 1);
                continue;
            }
            dp[w][t] = dp[w][t-1];
            if(0 < w) dp[w][t] = std::max(dp[w][t], dp[w-1][t-1]);
        }
    }

    int answer = 0;

    for(int i = 0; i <= W; ++i){
        answer = std::max(answer, dp[i][T - 1]);
    }

    cout << answer;
}

void Input() {
    cin >> T >> W;
    
    arr.resize(T);

    for(auto& a : arr) {
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