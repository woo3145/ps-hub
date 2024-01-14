#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::queue;
using std::pair;
using std::priority_queue;


int N, K;
int MAX_N = 100000;

void Solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> que;
    vector<bool> visited(MAX_N + 1, false);

    que.push({0, N});
    visited[N] = true;
    int answer = 0;
    while(!que.empty()){
        pair<int, int> cur = que.top();
        que.pop();
        
        visited[cur.second] = true;

        if(cur.second == K) {
            answer = cur.first;
            break;
        }
        if(0 < cur.second && !visited[cur.second - 1]) que.push({cur.first + 1, cur.second - 1});
        if(cur.second < MAX_N && !visited[cur.second + 1]) que.push({cur.first + 1, cur.second + 1});
        if(cur.second * 2 <= MAX_N && !visited[cur.second * 2]) que.push({cur.first, cur.second * 2});
    }

    cout << answer;
}

void Input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}

