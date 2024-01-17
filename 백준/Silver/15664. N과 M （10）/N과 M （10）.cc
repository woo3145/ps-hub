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
vector<int> answer;
vector<bool> visited;

void backTracking(int cur, int idx) {
    if(cur == M) {
        for(auto& a : answer){
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    int prev = 0;
    for(int i = idx; i < N; ++i){
        if(!visited[i] && arr[i] != prev){
            answer[cur] = arr[i];
            prev = arr[i];
            visited[i] = true;
            backTracking(cur + 1, i);
            visited[i] = false;
        }
    }
}

void Solve() {
    std::sort(arr.begin(), arr.end());

    backTracking(0, 0);
}

void Input() {
    cin >> N >> M;
    
    arr.resize(N);
    answer.resize(M, 0);
    visited.assign(N, false);

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