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
using std::priority_queue;
using std::lower_bound;

int N;
vector<int> arr;
vector<int> dp;
 
void Solve() {
    int result = 0;
    for(int i = 0; i < N; ++i){
        dp[arr[i]] = dp[arr[i] - 1] + 1;
        result = std::max(result, dp[arr[i]]);
    }

    cout << N - result;
}

void Input() {
    cin >> N;
    arr.resize(N);
    dp.resize(1000001, 0);
    for(auto& a : arr){
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
