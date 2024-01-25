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
    int y, x;
};

char board[12][6];
bool visited[12][6];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void print(){
    cout << "******" << '\n';

    for(int i = 0; i < 12; ++i){
        for(int j = 0; j < 6; ++j){
            cout << board[i][j] << ' ';
                
        }
        cout << '\n';
    }
}

bool bfs(int y, int x, char color){
    queue<Pos> que;
    vector<Pos> result;
    que.push({y, x});
    result.push_back({y, x});
    visited[y][x] = true;
    
    int count = 1;
    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || 12 <= ny || nx < 0 || 6 <= nx) continue;
            if(board[ny][nx] == '.') continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] != color) continue;
            que.push({ny, nx});
            result.push_back({ny, nx});
            visited[ny][nx] = true;
            ++count;
        }
    }
    if(4 <= count) {
        while(!result.empty()){
            int curY = result.back().y;
            int curX = result.back().x;
            result.pop_back();
            board[curY][curX] = '.';
        }
        return true;
    }
    return false;
}

void Solve() {
    int answer = 0;

    while(true){
        for(int i = 0; i < 12; ++i){
            for(int j = 0; j < 6; ++j){
                visited[i][j] = false;
            }
        }
        bool flag = false;
        // 터트릴 그룹 탐색
        for(int i = 0; i < 12; ++i){
            for(int j = 0; j < 6; ++j){
                if(visited[i][j] || board[i][j] == '.') continue;
                
                if(bfs(i, j, board[i][j])){
                    flag = true; 
                };
            }
        }
        
        // 더이상 터트릴게 없음
        if(!flag) break;

        // 뿌요들 아래로
        ++answer;

        for(int i = 0; i < 6; ++i){
            for(int j = 10; 0 <= j; --j){
                if(board[j][i] == '.') continue;
                int t = j;

                while(t < 11 && board[t + 1][i] == '.'){
                    ++t;
                }
                if(t != j) {
                    board[t][i] = board[j][i];
                    board[j][i] = '.';
                }
            }
        }
        
    }

    cout << answer;
}

void Input() {
    char c;
    for(int i = 0; i < 12; ++i){
        for(int j = 0; j < 6; ++j){
            cin >> c;
            board[i][j] = c;
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
