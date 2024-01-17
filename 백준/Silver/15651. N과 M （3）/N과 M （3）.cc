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

void backTracking(int cur) {
    if(cur == M){
        for(auto& a : arr){
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; ++i){
        arr[cur] = i;
        backTracking(cur + 1);
    }
}

void Solve() {
    backTracking(0);
}

void Input() {
    cin >> N >> M;
    
    arr.resize(M, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}