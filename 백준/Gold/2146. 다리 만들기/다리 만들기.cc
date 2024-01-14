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

struct Pos {
    int y, x;
};

int N;
vector<vector<int>> board;
Pos start;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void labeling(int y, int x, int label, vector<vector<bool>>& visited){
    queue<Pos> que;
    que.push({y, x});
    visited[y][x] = true;
    board[y][x] = label;

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] != 1) continue;

            que.push({ny, nx});
            visited[ny][nx] = true;
            board[ny][nx] = label;
        }
    }
}

int findBridge(int label){
    vector<vector<bool>> visited;
    visited.assign(N, vector<bool>(N, false));   
    queue<pair<Pos, int>> que;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j] == label){
                que.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    while(!que.empty()){
        Pos cur = que.front().first;
        int curCost = que.front().second;
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] != 0 && board[ny][nx] != label) {
                return curCost;
            };
            if(board[ny][nx] == 0){
                visited[ny][nx] = true;
                que.push({{ny, nx}, curCost + 1});
            }
        }
    }
}

void Solve() {
    vector<vector<bool>> visited;
    visited.assign(N, vector<bool>(N, false));    
    int label = 2;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(visited[i][j] || board[i][j] != 1) continue;
            labeling(i, j, label, visited);
            ++label;
        }
    }

    int answer = INT32_MAX;    
    for(int i = 2; i < label; ++i){
        answer = std::min(answer, findBridge(i));
    }

    cout << answer;
}

void Input() {
    cin >> N;
    board.resize(N, vector<int>(N));

    for(auto& y : board){
        for(auto& x : y){
            cin >> x;
        }
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

