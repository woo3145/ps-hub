#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::queue;

struct Pos {
    int y, x;
};

int N;
int MAX_H = INT32_MIN;;
int MIN_H = INT32_MAX;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<int>> board;


void bfs(int y, int x, int n, vector<vector<bool>>& visited){
    queue<Pos> que;
    que.push({y, x});

    visited[y][x] = true;

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] <= n) continue;

            que.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

void Solve() {
    int answer = 0;
    for(int n = MIN_H - 1; n <= MAX_H; ++n){
        int cnt = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(visited[i][j] || board[i][j] <= n) continue;
                bfs(i, j, n, visited);
                ++cnt;
            }
        }

        answer = std::max(answer, cnt);
    }
    cout << answer;
}

void Input() {
    cin >> N;
    board.assign(N, vector<int>(N, 0));

    for(auto& y : board){
        for(auto& x : y){
            cin >> x;
            MIN_H = std::min(MIN_H, x);
            MAX_H = std::max(MAX_H, x);
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

