#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::queue;
using std::pair;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int bfs(int y, int x) {
    int count = 0;
    queue<pair<int, int>> q;

    q.push({y, x});

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        if(visited[cur.first][cur.second]) continue;
        visited[cur.first][cur.second] = true;
        ++count;

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 0) continue;

            q.push({ny, nx});
        }
    }
    return count;
}

void Input() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    for(auto& n : board){
        for(auto& m : n){
            cin >> m;
        }
    }
}

void Solve() {
    int answer = 0;
    int maxCnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(visited[i][j]) continue;
            if(board[i][j] == 0) continue;
            ++answer;
            maxCnt = std::max(maxCnt, bfs(i, j));
        }
    }

    cout << answer << '\n';
    cout << maxCnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
