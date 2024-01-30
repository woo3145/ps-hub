#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;

struct Pos {
    int y, x;
};

int N, L, R;
vector<vector<int>> board;
int visited[50][50];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<pair<int, vector<Pos>>> record;

void bfs(int y, int x, int color) {
    queue<Pos> que;
    que.push({y, x});
    visited[y][x] = color;
    record.push_back({board[y][x], vector<Pos>(1, {y, x})});
    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
            if(visited[ny][nx] != 0) continue;
            int gap = std::abs(board[cur.y][cur.x] - board[ny][nx]);
            if(gap < L || R < gap) continue;

            visited[ny][nx] = color;
            que.push({ny, nx});
            record[color - 1].first += board[ny][nx];
            record[color - 1].second.push_back({ny, nx});
        }
    }
}


void Solve() {
    int answer = 0;
    
    while(true){
        int flag = true;
        record.clear();
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                visited[i][j] = 0;
            }
        }

        int color = 1;
        for(int i = 0 ; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(visited[i][j]) continue;
                bfs(i, j, color);
                ++color;
            }
        }

        for(auto& r : record){
            if(r.second.size() == 1) continue; // 인구이동 x

            int tmp = r.first / r.second.size();

            for(auto& p : r.second){
                board[p.y][p.x] = tmp;
            }
            flag = false;
        }
        if(flag) break;
        ++answer;
    }
    cout << answer;
}

void Input() {
    cin >> N >> L >> R;
    board.resize(N, vector<int>(N));
    for(auto& b : board){
        for(auto& n : b){
            cin >> n;
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
