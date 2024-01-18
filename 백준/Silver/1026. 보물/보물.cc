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
vector<int> arr_1, arr_2;

void Solve() {
    std::sort(arr_1.begin(), arr_1.end());
    std::sort(arr_2.rbegin(), arr_2.rend());

    int answer = 0;
    for(int i = 0; i < N; ++i){
        answer += arr_1[i] * arr_2[i];
    }
    cout << answer;
}

void Input() {
    cin >> N;
    arr_1.resize(N);
    arr_2.resize(N);

    for(auto& a : arr_1) cin >> a;
    for(auto& a : arr_2) cin >> a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}