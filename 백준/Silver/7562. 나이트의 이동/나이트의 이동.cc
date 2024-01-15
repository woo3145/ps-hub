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

int T;
int N;
vector<vector<int>> board;
Pos start;

const int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void Solve() {
    queue<Pos> que;
    que.push(start);

    if(board[start.y][start.x] == -1){
        cout << 0 << '\n';
        return;
    }

    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        for(int i = 0; i < 8; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N <= ny || nx < 0 || N <= nx) continue;
            if(board[ny][nx] == -1){
                cout << board[cur.y][cur.x] + 1 << '\n';
                return;
            }
            if(board[ny][nx] == 0){
                que.push({ny, nx});
                board[ny][nx] = board[cur.y][cur.x] + 1;
            }
        }
    }
}

void Input() {
    cin >> N;
    board.clear();
    board.assign(N, vector<int>(N, 0));
    
    cin >> start.y >> start.x;
    int y, x;
    cin >> y >> x;
    board[y][x] = -1;
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

