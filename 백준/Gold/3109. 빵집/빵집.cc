#include <iostream>
#include <vector>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, M;
vector<vector<char>> board; 

void Input() {
    cin >> N >> M;
    board.resize(N);
    
    for(auto& n : board) {
        n.resize(M);
        for(auto& m : n){
            cin >> m;
        }
    };
}

bool visited[10001][501];

bool dfs(int y, int x){
    if(y < 0 || N <= y || x < 0 || M <= x) return false;
    if(board[y][x] == 'x') return false;
    if(visited[y][x]) return false;
    visited[y][x] = true;
    if(x == M - 1) return true;

    return dfs(y - 1, x + 1) || dfs(y, x + 1) || dfs(y + 1, x + 1);
}

void Solve() {
    int answer = 0;
    for(int i = 0; i < N; ++i){
        if(dfs(i, 0)){
            ++answer;
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
