#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::queue;
using std::pair;

struct Pos {
    int y, x;
};

int N, M;
vector<vector<int>> board;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};


void check(int y, int x, vector<vector<bool>>& visited) {
    queue<Pos> que;
    que.push({y, x});

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();
        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 0) continue;

            que.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

void melt() {
    vector<vector<int>> result;
    result.assign(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(board[i][j] == 0) continue;

            int cnt = 0;
            for(int k = 0; k < 4; ++k){
                int ny = dy[k] + i;
                int nx = dx[k] + j;

                if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
                if(board[ny][nx] != 0) continue;
                ++cnt;
            }
            int rest = board[i][j] - cnt;
            if(0 < rest) result[i][j] = rest;
        }
    }

    board = result;
}

void Solve() {
    int answer = 0;
    
    while(true){
        int island = 0;
        vector<vector<bool>> visited;
        visited.assign(N, vector<bool>(M, false));

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(board[i][j] != 0 && !visited[i][j]) {
                    ++island;
                    check(i, j, visited);   
                };
            }
        }

        if(island == 0) {
            answer = 0;
            break;
        }

        if(2 <= island){
            break;
        }

        melt();
        ++answer;
    }

    cout << answer;
}

void Input() {
    cin >> N >> M;
    board.assign(N, vector<int>(M));
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
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
