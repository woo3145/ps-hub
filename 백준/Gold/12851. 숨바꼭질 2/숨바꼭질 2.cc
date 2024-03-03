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

int N, K;
bool visited[100001];

void Solve() {
    bool first = true;
    int minTime = 0;
    int answer = 0;
    queue<pair<int, int>> que;
    
    que.push({N, 0});
    while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        visited[cur.first] = true;

        if(!first && cur.second == minTime && cur.first == K){
            ++answer;
        }
        if(first && cur.first == K){
            ++answer;
            minTime = cur.second;
            first = false;
        }

        if(0 <= cur.first - 1 && cur.first - 1 < 100001 && !visited[cur.first - 1]){
            que.push({cur.first - 1, cur.second + 1});
        }
        if(0 <= cur.first + 1 && cur.first + 1 < 100001 && !visited[cur.first + 1]) {
            que.push({cur.first + 1, cur.second + 1});
        }
        if(0 <= cur.first * 2 && cur.first * 2 < 100001 && !visited[cur.first * 2]) {
            que.push({cur.first * 2, cur.second + 1});
        }
    }

    cout << minTime << '\n' << answer;
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