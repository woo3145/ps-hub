#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

struct CCTV {
    int y, x, type;
};

int N, M;
vector<CCTV> cctv;
vector<vector<int>> board;
vector<vector<int>> visited;
int C, S;
int answer = 0;

int check(CCTV& c, int d, int cost) {
    int ny = c.y;
    int nx = c.x;
    int count = 0;
    if(c.type == 1){
        int dy = 0;
        int dx = 0;
        if(d == 0) {
            dy = -1;
        }else if(d == 1){
            dx = 1;
        }else if(d == 2){
            dy = 1;
        }else {
            dx = -1;
        }
        while(true){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
    }else if(c.type == 2){
        while(true){
            if(d == 0){
                nx += 1;
            }else{
                ny += 1;
            }

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
        ny = c.y;
        nx = c.x;
        while(true){
            if(d == 0){
                nx -= 1;
            }else{
                ny -= 1;
            }

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
    }else if(c.type == 3){
        int dy = 0;
        int dx = 0;
        if(d == 0) {
            dy = -1;
        }else if(d == 1){
            dx = 1;
        }else if(d == 2){
            dy = 1;
        }else {
            dx = -1;
        }
        while(true){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
        ny = c.y;
        nx = c.x;
        if(d == 0) {
            dx = 1;
            dy = 0;
        }else if(d == 1){
            dy = 1;
            dx = 0;
        }else if(d == 2){
            dx = -1;
            dy = 0;
        }else {
            dy = -1;
            dx = 0;
        }
        while(ny < N && 0 <= ny && nx < M && 0 <= nx){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
    }else if(c.type == 4){
        int dy = 0;
        int dx = 0;
        if(d == 0) {
            dy = -1;
        }else if(d == 1){
            dx = 1;
        }else if(d == 2){
            dy = 1;
        }else {
            dx = -1;
        }
        while(true){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
        ny = c.y;
        nx = c.x;
        if(d == 0) {
            dx = 1;
            dy = 0;
        }else if(d == 1){
            dy = 1;
            dx = 0;
        }else if(d == 2){
            dx = -1;
            dy = 0;
        }else {
            dy = -1;
            dx = 0;
        }
        while(ny < N && 0 <= ny && nx < M && 0 <= nx){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
        ny = c.y;
        nx = c.x;
        if(d == 0) {
            dy = 1;
            dx = 0;
        }else if(d == 1){
            dx = -1;
            dy = 0;
        }else if(d == 2){
            dy = -1;
            dx = 0;
        }else {
            dx = 1;
            dy = 0;
        }
        while(ny < N && 0 <= ny && nx < M && 0 <= nx){
            ny += dy;
            nx += dx;

            if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
            if(board[ny][nx] == 6) break;
            if(visited[ny][nx] == 0) ++count;
            visited[ny][nx] += cost;
        }
    }else{
        int dy[4] = {-1, 0, 1, 0};
        int dx[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; ++i){
            ny = c.y;
            nx = c.x;
            while(true){
                ny += dy[i];
                nx += dx[i];
                if(ny < 0 || N <= ny || nx < 0 || M <= nx) break;
                if(board[ny][nx] == 6) break;
                if(visited[ny][nx] == 0) ++count;
                visited[ny][nx] += cost;
            }   
        }
    }

    return count;
}

void backTracking (int idx, int sum) {
    if(idx == C) {
        answer = std::max(answer, sum);
        return;
    }

    if(cctv[idx].type == 1){
        for(int i = 0; i < 4; ++i){
            backTracking(idx + 1, sum + check(cctv[idx], i, 1));
            check(cctv[idx], i, -1);
        }
    }else if(cctv[idx].type == 2){
        for(int i = 0; i < 2; ++i){
            backTracking(idx + 1, sum + check(cctv[idx], i, 1));
            check(cctv[idx], i, -1);
        }
    }else if(cctv[idx].type == 3){
        for(int i = 0; i < 4; ++i){
            backTracking(idx + 1, sum + check(cctv[idx], i, 1));
            check(cctv[idx], i, -1);
        }
    }else if(cctv[idx].type == 4){
        for(int i = 0; i < 4; ++i){
            backTracking(idx + 1, sum + check(cctv[idx], i, 1));
            check(cctv[idx], i, -1);
        }
    }else{
        backTracking(idx + 1, sum + check(cctv[idx], 0, 1));
        check(cctv[idx], 0, -1);
    }
}

void Solve() {

    backTracking(0, 0);
    cout << S - answer;
}

void Input() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
            if(board[i][j] == 0) ++ S;
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv.push_back({i, j, board[i][j]});
                board[i][j] = 0;
                visited[i][j] = 1;
                ++C; // 카메라 수
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
