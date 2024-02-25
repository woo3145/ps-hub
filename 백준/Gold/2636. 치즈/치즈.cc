#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;
using std::deque;
using std::queue;

struct Pos {
    int y, x;
};

int N, M;
vector<vector<int>> board;
queue<Pos> que;
queue<Pos> tmp;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Solve() {
    int day = 0;
    int answer = 0;
    que.push({0, 0});
    while(true){
        answer = que.size();

        while(!que.empty()){
            Pos cur = que.front();
            que.pop();

            for(int i = 0; i < 4; ++i){
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
                if(board[ny][nx] == -1) continue;
                if(board[ny][nx] == 1) {
                    tmp.push({ny, nx});
                }else {
                    que.push({ny, nx});
                }
                board[ny][nx] = -1;
            }
        }

        if(tmp.empty()) break;

        ++day;
        while(!tmp.empty()){
            que.push(tmp.front());
            tmp.pop();
        }
    }
    cout << day << '\n' << answer;
}

void Input() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    for(auto& n : board){
        for(auto& m : n){
            cin >> m;
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
