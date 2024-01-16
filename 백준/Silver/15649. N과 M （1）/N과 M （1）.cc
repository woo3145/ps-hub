#include <iostream>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, M;
vector<int> arr;
vector<bool> visited;

void backTracking(int m){
    if(m == M){
        for(auto& a : arr){
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; ++i){
        if(visited[i]) continue;

        visited[i] = true;
        arr[m] = i;
        backTracking(m + 1);
        visited[i] = false;
    }
}

void Solve() {
    backTracking(0);
}

void Input() {
    cin >> N >> M;
    arr.assign(M, 0);
    visited.assign(N + 1, false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}