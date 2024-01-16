#include <iostream>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N;
int answer = 0;
vector<bool> visited_1;
vector<bool> visited_2;
vector<bool> visited_3;

void backTracking(int c){
    if(c == N) {
        ++answer;
        return;
    }

    for(int i = 0; i < N; ++i){
        if(visited_1[i] || visited_2[c + i] || visited_3[c - i + N - 1]) continue;

        visited_1[i] = true;
        visited_2[c + i] = true;
        visited_3[c - i + N - 1] = true;
        backTracking(c + 1);
        visited_1[i] = false;
        visited_2[c + i] = false;
        visited_3[c - i + N - 1] = false;
    }
}

void Solve() {
    backTracking(0);
    cout << answer;
}

void Input() {
    cin >> N;
    visited_1.assign(N * 2 + 1, false);
    visited_2.assign(N * 2 + 1, false);
    visited_3.assign(N * 2 + 1, false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}