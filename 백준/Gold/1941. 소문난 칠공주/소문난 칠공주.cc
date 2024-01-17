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
    int y, x;
};

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<vector<char>> board;
vector<int> arr;
vector<bool> selected;

bool bfs(){
    vector<vector<char>> tmp = vector<vector<char>>(5, vector<char>(5, '.'));
    Pos start;

    for(int i = 0; i < 25; ++i){
        if(!selected[i]) continue;
        int y = i / 5;
        int x = i % 5;
        tmp[y][x] = board[y][x];
        start.y = y;
        start.x = x;
    }
    int sCnt = 0;
    int yCnt = 0;
    queue<Pos> que;

    que.push(start);

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 4; ++i){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny < 0 || 5 <= ny || nx < 0 || 5 <= nx) continue;
            if(tmp[ny][nx] == '.') continue;
            que.push({ny, nx});
            if(tmp[ny][nx] == 'Y') ++yCnt;
            if(tmp[ny][nx] == 'S') ++sCnt;

            tmp[ny][nx] = '.';
        }
    }
    if(yCnt + sCnt != 7){
        return false;
    }
    return 4 <= sCnt;
}

void Solve() {
    int answer = 0;
    do{
        if(bfs()){
            ++answer;
        }
    }while(std::prev_permutation(selected.begin(), selected.end()));

    cout << answer;
}

void Input() {
    board.resize(5, vector<char>(5));
    arr.resize(25);
    selected.assign(25, false);
    for(auto& y : board){
        for(auto& x : y){
            cin >> x;
        }
    }
    for(int i = 0; i < 25; ++i){
        arr[i] = i;
    }
    for(int i = 0; i < 7; ++i){
        selected[i] = true;
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