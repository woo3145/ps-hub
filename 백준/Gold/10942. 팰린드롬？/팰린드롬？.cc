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


int N, M;
vector<int> arr;
vector<vector<int>> dp;
vector<pair<int,int>> queries;

void Solve() {

    for(int i = 1; i <= N; ++i){
        dp[i][i] = 1; // 한자리수
    }

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j + i <= N; ++j){
            if(arr[j] != arr[j + i]) continue;
            
            if(i == 1 || dp[j + 1][j + i - 1]){
                dp[j][j + i] = true;
            }
        }
    }

    for(auto& q : queries){
        cout << dp[q.first][q.second] << '\n';
    }
}

void Input() {
    cin >> N;

    arr.resize(N + 1);
    dp.resize(N + 1, vector<int>(N + 1));

    for(int i = 1; i <= N; ++i){
        cin >> arr[i];
    }

    cin >> M;
    queries.resize(M);
    for(auto& a : queries){
        cin >> a.first >> a.second;
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
