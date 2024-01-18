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
vector<int> arr; 
vector<int> dp;

void Solve() {
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= i; ++j){
            dp[i] = std::max(dp[i], dp[i - j] + arr[j]);
        }
    }
    cout << dp[N];
}

void Input() {
    cin >> N;
    arr.resize(N + 1, 0);
    dp.resize(N + 1, 0);
    
    for(int i = 1; i <= N; ++i){
        cin >> arr[i];
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