#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::queue;
using std::deque;

struct Pos {
    int y, x;
};

int N, M, P;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

vector<int> arr;
vector<vector<int>> board;
vector<int> answer;

void Solve() {
    queue<Pos> que[10];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(board[i][j] == 0 || board[i][j] == -1) continue;
            que[board[i][j]].push({i, j});
        }
    }

    while(true){
        int flag = true;

        for(int p = 1; p <= P; ++p){
            int cnt = arr[p - 1];
            while(!que[p].empty() && cnt--){
                
                int limit = que[p].size();

                while(limit--){
                    Pos cur = que[p].front();
                    que[p].pop();

                    for(int i = 0; i < 4; ++i){
                        int ny = cur.y + dy[i];
                        int nx = cur.x + dx[i];

                        if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
                        if(board[ny][nx] != 0) continue;
                        que[p].push({ny, nx});
                        board[ny][nx] = board[cur.y][cur.x];
                        answer[board[ny][nx] - 1] += 1;
                        flag = false;
                    }
                }
            }
        }
       
        if(flag) break;
    }

    for(auto& a : answer){
        cout << a << ' ';
    }

}

void Input() {
    cin >> N >> M >> P;
    answer.assign(P, 0);
    arr.resize(P);
    for(auto& p : arr){
        cin >> p;
    }

    board.assign(N, vector<int>(M, -1));
    char c;
    for(auto& y : board){
        for(auto& x : y){
            cin >> c;
            if(c == '.') x = 0;
            else if(c == '#') x = -1;
            else {
                x = c - '0';
                answer[x - 1] += 1;
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

