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


int N, M;
vector<vector<char>> board;
vector<vector<int>> dp;

void Solve() {
    int answer = 0;
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(board[i][j] == '0') continue;
            
            dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;

            answer = std::max(answer, dp[i][j]);
        }
    }

    cout << answer * answer;
}

void Input() {
    cin >> N >> M;

    board.resize(N + 1, vector<char>(M + 1));
    dp.resize(N + 1, vector<int>(M + 1));

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            cin >> board[i][j];
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
