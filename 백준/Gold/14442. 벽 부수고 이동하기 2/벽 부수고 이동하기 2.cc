#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::queue;
using std::pair;
using std::map;

struct Pos {
    int y, x, dist, cnt;
};

int N, M, K;
bool visited[11][1001][1001];
string board[1001];
const int dy[4] = {-1, 0 , 1, 0};
const int dx[4] = {0, 1, 0, -1};

void Input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; ++i){
        cin >> board[i];
    }
}

void Solve() {
    queue<Pos> q;

    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;
    int answer = -1;
    while(!q.empty()){
        Pos cur = q.front();
        q.pop();
        if(cur.y == N - 1 && cur.x == M - 1) {
            answer = cur.dist;
            break;
        }

        for(int i = 0; i < 4; ++i){
            int ny = dy[i] + cur.y;
            int nx = dx[i] + cur.x;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
            if(visited[cur.cnt][ny][nx]) continue;

            if(board[ny][nx] == '0'){
                q.push({ny, nx, cur.dist + 1, cur.cnt});
                visited[cur.cnt][ny][nx] = true;
            }else if (cur.cnt < K && !visited[cur.cnt + 1][ny][nx]){
                q.push({ny, nx, cur.dist + 1, cur.cnt + 1});
                visited[cur.cnt + 1][ny][nx] = true;
            }
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
