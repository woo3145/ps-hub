#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::queue;
using std::pair;

struct Pos {
    int z, y, x;
};

int L, N, M;
vector<vector<vector<char>>> board;
Pos start;

const int dz[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 0, 1, 0};
const int dx[6] = {0, 0, 0, 1, 0, -1};

int bfs(){
    queue<pair<Pos, int>> que;
    que.push({start, 0});

    while(!que.empty()){
        Pos cur = que.front().first;
        int curCnt = que.front().second;
        que.pop();

        for(int i = 0; i < 6; ++i){
            int nz = dz[i] + cur.z;
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(nz < 0 || L <= nz || ny < 0 || N <= ny || nx < 0 || M <= nx) continue;

            if(board[nz][ny][nx] == 'E'){
                return curCnt + 1;
            }

            if(board[nz][ny][nx] == '.'){
                que.push({Pos({nz, ny, nx}), curCnt + 1});
                board[nz][ny][nx] = 'S';
            }
        }
    }

    return -1;
}

void Solve() {
    int result = bfs();

    if(result == -1){
        cout << "Trapped!\n";
    }else{
        cout << "Escaped in " << result << " minute(s).\n";
    }
}

void Input() {
    cin >> L >> N >> M;
    if(L == 0 && N == 0 && M == 0) return;
    board.clear();
    board.resize(L, vector<vector<char>>(N, vector<char>(M)));

    for(int l = 0; l < L; ++l){
        for(int n = 0; n < N; ++n){
            for(int m = 0; m < M; ++m){
                cin >> board[l][n][m];
                if(board[l][n][m] == 'S') start = Pos({l, n, m});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true){
        Input();
        if(L == 0 && N == 0 && M == 0) break;
        Solve();    
    }
    
    return 0;
}

