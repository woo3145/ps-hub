#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <list>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::deque;
using std::list;

struct Pos {
    int z, y, x;
};

bool board[5][5][5];
int visited[5][5][5];

int answer = INT32_MAX;
vector<vector<int>> cases;

const int dy[6] = {-1, 1, 0, 0, 0, 0};
const int dx[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs(vector<int>& order){

    if(!board[order[0]][0][0] || !board[order[4]][4][4]) return 0;

    // 방문배열 초기화
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            for(int k = 0; k < 5; ++k){
                visited[i][j][k] = 0;
            }
        }
    }
    queue<Pos> que;
    que.push({0, 0, 0});
    visited[0][0][0] = 1;
    
    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 6; ++i){
            int nz = dz[i] + cur.z;
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(nz < 0 || 5 <= nz || ny < 0 || 5 <= ny || nx < 0 || 5 <= nx) continue;
            if(!board[order[nz]][ny][nx]) continue;
            if(visited[nz][ny][nx] != 0) continue;
            que.push({nz, ny, nx});
            visited[nz][ny][nx] = visited[cur.z][cur.y][cur.x] + 1;
        }
    }

    return visited[4][4][4];
}

void rotate(int z) {
    int temp[5][5];

    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            temp[4 - j][i] = board[z][i][j];
        }
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            board[z][i][j] = temp[i][j];
        }
    }
}

void recur(int depth){
    if(depth == 5){
        for(auto& c : cases){
            int t = bfs(c);
            if(t == 0) continue;
            answer = std::min(answer, t - 1);
        }
        return;
    }

    for(int i = 0; i < 4; ++i){
        recur(depth + 1);
        rotate(depth);
    }
}

void Solve() {
    // 판을 놓을 경우의수 구해놓기
    vector<int> temp = {0, 1, 2, 3, 4};
    do{
        cases.push_back(temp);
    }while(std::next_permutation(temp.begin(), temp.end()));
    
    recur(0);

    cout << (answer == INT32_MAX ? -1 : answer);
}

void Input() {
    
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            for(int k = 0; k < 5; ++k){
                cin >> board[i][j][k];
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
