#include <iostream>
#include <vector>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N;
vector<int> arr;

void Input() {
    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
}

void Solve() {
    vector<int> dp(N, 0);

    for(int i = 0; i < N; ++i){
        dp[i] = arr[i];

        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) dp[i] = dp[j] + arr[i];
        }
    }
    cout << *std::max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}