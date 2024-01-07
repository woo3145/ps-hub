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
vector<vector<char>> board;
vector<vector<pair<int,int>>> visited; // F, J
int jy, jx;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void Input() {
    cin >> N >> M;
    board.assign(N, vector<char>(M));
    visited.assign(N, vector<pair<int,int>>(M, {0, 0}));

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'J'){
                jy = i;
                jx = j;
            }
        }
    }
}

void Solve() {
    queue<pair<int, int>> q;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(board[i][j] == 'F'){
                q.push({i, j});
                visited[i][j].first = 1;
            }
        }
    }

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(board[ny][nx] == '#') continue;
            if(visited[ny][nx].first != 0) continue;

            visited[ny][nx].first = visited[cur.first][cur.second].first + 1;
            q.push({ny, nx});
        }
    }

    q.push({jy, jx});
    visited[jy][jx].second = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        if(cur.first == 0 || cur.first == N - 1 || cur.second == 0 || cur.second == M - 1){
            cout << visited[cur.first][cur.second].second;
            return;
        }

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(board[ny][nx] == '#') continue;
            if(visited[ny][nx].second != 0) continue;
            if(visited[ny][nx].first && visited[ny][nx].first <= visited[cur.first][cur.second].second + 1) continue;

            visited[ny][nx].second = visited[cur.first][cur.second].second + 1;
            q.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
