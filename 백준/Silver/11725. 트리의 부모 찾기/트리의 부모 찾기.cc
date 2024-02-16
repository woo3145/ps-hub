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

int N;
vector<int> graph[100001];
bool visited[100001];
int answer[100001];

void dfs(int cur) {
    visited[cur] = true;
    for(int i = 0; i < graph[cur].size(); ++i){
        if(visited[graph[cur][i]]) continue;
        answer[graph[cur][i]] = cur;
        dfs(graph[cur][i]);
    }
}

void Solve() {
    dfs(1);

    for(int i = 2; i <= N; ++i){
        cout << answer[i] << '\n';
    }
}

void Input() {
    cin >> N;
    int a, b;
    for(int i = 0; i < N - 1; ++i){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
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
