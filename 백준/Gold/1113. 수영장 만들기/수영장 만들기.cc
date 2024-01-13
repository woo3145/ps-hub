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

int N, M;
int MAX_H = 0;
vector<vector<int>> board;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void bfs(int height){
    queue<Pos> que;
    board[0][0] = height;
    que.push({0, 0});

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N + 1 < ny || nx < 0 || M + 1 < nx) continue;
            if(height <= board[ny][nx]) continue;
            board[ny][nx] = height;
            que.push({ny, nx});
        }
    }
}

void Solve() {
    int answer = 0;
    for(int h = 1; h <= MAX_H; ++h){
        bfs(h);

        for(int y = 1; y <= N; ++y){
            for(int x = 1; x <= M; ++x){
                if(board[y][x] < h) {
                    ++answer;
                    board[y][x] += 1;
                }
            }
        }
    }

    cout << answer;
}

void Input() {
    cin >> N >> M;
    board.assign(N + 2, vector<int>(M + 2));
    
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            char a;
            cin >> a;
            int n = a - '0';
            MAX_H = std::max(MAX_H, n);
            board[i][j] = n;
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
