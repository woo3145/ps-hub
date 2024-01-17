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

struct Task {
    int d, c;
};

int N;
vector<Task> tasks; 
vector<int> dp;


void Solve() {
    if(tasks[N-1].d == 1){
        dp[N - 1] = tasks[N-1].c;
    }
    for(int i = N - 2; 0 <= i; --i){
        dp[i] = dp[i + 1];
        if(N < i + tasks[i].d) continue;
        dp[i] = std::max(dp[i], dp[i + tasks[i].d] + tasks[i].c);
    }

    cout << dp[0];
}

void Input() {
    cin >> N;
    
    tasks.resize(N);
    dp.assign(N + 1, 0);

    for(auto& t : tasks) {
        cin >> t.d >> t.c;
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
