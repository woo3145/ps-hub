#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;

int N;
queue<pair<int, int>> answer;

void move(int cur, int from, int to, int sub){
    if(cur == 0) return;

    move(cur - 1, from, sub, to);
    answer.push({from, to});
    move(cur - 1, sub, to, from);
}

void Solve() {
    move(N, 1, 3, 2);

    cout << answer.size() << '\n';
    while(!answer.empty()){
        cout << answer.front().first << ' ' <<answer.front().second << '\n';
        answer.pop();
    }
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