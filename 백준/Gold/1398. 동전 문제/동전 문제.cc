#include <iostream>
#include <algorithm>

#define ull unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::min;

int T;
int dp[100];

void Input() {
    cin >> T;
}

void CreateDP() {
    for(int i = 1; i < 100; ++i){
        dp[i] = dp[i-1] + 1;
        if(10 <= i){
            dp[i] = min(dp[i], dp[i - 10] + 1);
        }
        if(25 <= i){
            dp[i] = min(dp[i], dp[i - 25] + 1);
        }
    }
}
// 2
// 250111
// 76540123
void Solve() {
    ull n;
    cin >> n;

    ull answer = 0;
    while(n) {
        answer += dp[n % 100];
        n /= 100;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    CreateDP();
    Input();
    for(int i = 0; i < T; ++i){
        Solve();
    }

    return 0;
}
