#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;
using std::queue;

typedef long long ll;

int N;
ll arr[26];

void Solve() {
    string s;
    for(int i = 0; i < N; ++i){
        cin >> s;
        int t = 1;
        for(int i = s.length() - 1; 0 <= i; --i){
            arr[s[i] - 'A'] += t;
            t *= 10;
        }
    }
    std::sort(arr, arr + 26, [](auto& a, auto& b) {
        return a > b;
    });

    ll answer = 0;
    for(int i = 0; i < 10; ++i){
        answer += arr[i] * (9 - i);
    }
    cout << answer;
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
