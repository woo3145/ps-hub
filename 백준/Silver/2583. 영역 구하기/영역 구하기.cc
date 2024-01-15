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

int M, N, K;
vector<vector<int>> board;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int bfs(int y, int x){
    int size = 1;
    queue<Pos> que;
    que.push({y, x});
    board[y][x] = 1;

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || M <= ny || nx < 0 || N <= nx) continue;
            if(board[ny][nx] != 0) continue;

            que.push({ny, nx});
            board[ny][nx] = 1;
            ++size;
        }
    }

    return size;
}

void Solve() {
    queue<Pos> que;
    vector<int> answer;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j] == 0){
                answer.push_back(bfs(i, j));
            }
        }
    }

    cout << answer.size() << '\n';
    std::sort(answer.begin(), answer.end());
    for(auto& n : answer){
        cout << n << ' ';
    }
}

void Input() {
    cin >> M >> N >> K;

    board.assign(M, vector<int>(N, 0));

    int x1, y1, x2, y2;
    
    for(int i = 0; i < K; ++i){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; ++y){
            for(int x = x1; x < x2; ++x){
                board[y][x] = 1;
            }
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

