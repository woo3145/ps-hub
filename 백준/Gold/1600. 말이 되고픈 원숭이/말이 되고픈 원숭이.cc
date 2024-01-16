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
    int y, x, k, cost;
};

int K, W, H;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
const int dy_night[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dx_night[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

vector<vector<int>> board;
bool visited[31][201][201];

void Solve() {
    queue<Pos> que;
    que.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        if(cur.y == H - 1 && cur.x == W - 1){
            cout << cur.cost;
            return;
        }
        if(cur.k < K) {
            for(int i = 0; i < 8; ++i){
                int ny = dy_night[i] + cur.y;
                int nx = dx_night[i] + cur.x;

                if(ny < 0 || H <= ny || nx < 0 || W <= nx) continue;
                if(visited[cur.k + 1][ny][nx]) continue;
                if(board[ny][nx]) continue;

                visited[cur.k + 1][ny][nx] = true;
                que.push({ny, nx, cur.k + 1, cur.cost + 1});
            }
        }

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || H <= ny || nx < 0 || W <= nx) continue;
            if(visited[cur.k][ny][nx]) continue;
            if(board[ny][nx]) continue;

            visited[cur.k][ny][nx] = true;
            que.push({ny, nx, cur.k, cur.cost + 1});
        }
    }
    cout << -1;
}

void Input() {
    cin >> K >> W >> H;
    board.assign(H, vector<int>(W, 0));

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

