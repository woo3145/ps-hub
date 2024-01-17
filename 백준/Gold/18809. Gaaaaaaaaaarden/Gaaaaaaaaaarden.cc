#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;

struct Pos {
    int y, x, color, cnt;
};

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int N, M, G, R;
vector<vector<pair<int, int>>> board; // 0호수, 1땅, 2땅(배양액 가능), 3빨강, 4초록, 5꽃
vector<int> possibleLand;
vector<int> selected;

int bfs(vector<vector<pair<int,int>>> _board) {
    int ret = 0;
    queue<Pos> que;
    for(int i = 0; i < possibleLand.size(); ++i){
        if(selected[i] == 0) continue;
        int y = possibleLand[i] / M;
        int x = possibleLand[i] % M;
        que.push({y, x, selected[i]});
        _board[y][x].first = selected[i];
    }

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();
        if(_board[cur.y][cur.x].first == 5) continue;
        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(_board[ny][nx].first == 0) continue;
            if(_board[ny][nx].first == 5) continue;

            if(_board[ny][nx].first == 1 || _board[ny][nx].first == 2) {
                que.push({ny, nx, cur.color});
                _board[ny][nx].first = cur.color;
                _board[ny][nx].second = _board[cur.y][cur.x].second + 1;
            }else{
                if(_board[ny][nx].first == cur.color) continue;
                if(_board[ny][nx].second != _board[cur.y][cur.x].second + 1) continue;
                // 꽃 핌
                _board[ny][nx].first = 5;
                ++ret;
            }
        }
    }

    return ret;
}

void Solve() {
    int answer = 0;
    // 배양액 경우의 수
    do{
        int result = bfs(board);
        answer = std::max(answer, result);
    }while(std::prev_permutation(selected.begin(), selected.end()));

    cout << answer;
}

void Input() {
    cin >> N >> M >> G >> R;
    
    board.resize(N, vector<pair<int,int>>(M));

    int t;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> t;
            board[i][j].first = t;
            board[i][j].second = 0;
            if(t == 2){
                possibleLand.push_back(i * M + j);
            }
        }
    }
    selected.assign(possibleLand.size(), 0);
    for(int i = 0; i < G; ++i) selected[i] = 4; // 초록 배양액
    for(int i = 0; i < R; ++i) selected[G + i] = 3; // 빨강 배양액
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
