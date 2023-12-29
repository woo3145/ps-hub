#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int N, M;
int board[51][51];

void Input() {
    cin >> N >> M;
    for(int i =0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            char c;
            cin >> c;
            board[i][j] = (int)c;
        }
    }
}
void Solve() {
    int answer = 1;
    int MAX_W = N < M ? N : M;
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            for(int width = 1; width < MAX_W; ++width){
                if(i + width < N && j + width < M 
                && board[i][j] == board[i][j + width] 
                && board[i][j] == board[i+width][j] 
                && board[i][j] == board[i+width][j+width]){
                    answer = answer < width + 1 ? width+1 : answer;
                }
            }
        }
    }

    cout << answer * answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}
