#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::queue;
using std::map;

struct Pos {
    int y, x;
};

int T;
int H, W;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<char>> board;
map<char, bool> keys;

void Solve() {
    
    queue<Pos> que;
    vector<Pos> lockDoor[26];
    
    int answer = 0;
    que.push({0, 0});

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || H + 1 < ny || nx < 0 || W + 1 < nx) continue;
            if(board[ny][nx] == '*') continue;
            if(board[ny][nx] == '.' || board[ny][nx] == '$'){
                if(board[ny][nx] == '$') {
                    ++answer;
                }
                que.push({ny, nx});
                board[ny][nx] = '*';
            // 문 발견
            }else if (board[ny][nx] - 'A' < 26){
                // 키가 존재
                if(keys.find(board[ny][nx]) != keys.end()) {
                    que.push({ny, nx});
                    board[ny][nx] = '*';
                }else{
                    // 키가 없음
                    lockDoor[board[ny][nx] - 'A'].push_back({ny, nx});
                    board[ny][nx] = '*';
                }
            
            // 열쇠 발견
            }else if (board[ny][nx] - 'a' < 26){
                keys.insert({board[ny][nx] - 32, true});
                while(!lockDoor[board[ny][nx] - 'a'].empty()){
                    que.push(lockDoor[board[ny][nx] - 'a'].back());
                    lockDoor[board[ny][nx] - 'a'].pop_back();
                }
                que.push({ny, nx});
                board[ny][nx] = '*';
            }
        }
    }
    cout << answer << '\n';
}

void Input() {
    cin >> H >> W;
    board.clear();
    keys.clear();

    board.assign(H + 2, vector<char>(W + 2, '.'));
    
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cin >> board[i][j];
        }
    }
    string k;
    cin >> k;
    for(auto& s : k){
        if(s == '0') continue;
        keys.insert({s - 32, true});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for(int i = 0; i < T; ++i){
        Input();
        Solve();    
    }    
    return 0;
}
