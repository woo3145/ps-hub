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
using std::deque;
using std::queue;


int N, X, Y, M;
vector<int> arr[101];
bool visited[101];

void Solve() {
    queue<pair<int, int>> que;

    que.push({X, 0});
    visited[X] = true;

    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();

        if(cur.first == Y) {
            cout << cur.second;
            return;
        }
        visited[cur.first] = true;

        for(auto& a : arr[cur.first]){
            if(visited[a]) continue;
            que.push({a, cur.second + 1});
        }
    }
    cout << -1;
}

void Input() {
    cin >> N >> X >> Y >> M;
    int x, y;

    for(int i = 0; i < M; ++i){
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
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
