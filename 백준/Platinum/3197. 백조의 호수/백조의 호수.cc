#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::queue;
using std::deque;
using std::map;

struct Pos {
    int y, x;
};

int R, C;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<char>> board;
vector<vector<bool>> visited;
queue<Pos> swan, water;

void melt(){
    queue<Pos> _water;

    while(!water.empty()){
        Pos cur = water.front();
        water.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
            if(board[ny][nx] != 'X') continue;
            _water.push({ny, nx});
            board[ny][nx] = '.';
        }
    }

    water = _water;
}

int moveSwan(){
    queue<Pos> _swan;

    while(!swan.empty()){
        Pos cur = swan.front();
        swan.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || R <= ny || nx < 0 || C <= nx) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 'L') return true;
            if(board[ny][nx] == 'X') {
                _swan.push({ny, nx});
            }else{
                swan.push({ny, nx});
            }
            visited[ny][nx] = true;
        }
    }

    swan = _swan;
    return false;
}

void Solve() {
    int answer = 0;

    while(true){
        if(moveSwan()){
            cout << answer;
            break;
        }
        melt();
        ++answer;

        
    }
}

void Input() {
    cin >> R >> C;

    board.assign(R, vector<char>(C, 'X'));
    visited.assign(R, vector<bool>(C, false));
    
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            cin >> board[i][j];
            if(board[i][j] == '.' || board[i][j] == 'L') {
                if(board[i][j] == 'L') swan.push({i, j});
                water.push({i, j});
            }
        }
    }
    swan.pop(); // 한마리만 남기기
    board[swan.front().y][swan.front().x] = '.';
    visited[swan.front().y][swan.front().x] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}
