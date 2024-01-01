#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int N, M;
vector<vector<int>> board;

int maxCost = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input() {
    cin >> N >> M;
    board.reserve(N);

    for(int i = 0; i < N; ++i){
        vector<int> l;
        l.reserve(M);
        int a;
        for(int j = 0; j < M; ++j){
            cin >> a;
            l.push_back(a);
        }
        board.push_back(l);
    }
}

void Solve() {
    string answer = "";

    // 홀홀 or 홀짝
    if(N % 2 == 1){

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M - 1; ++j){
                if(i % 2 == 0){
                    answer += "R";
                }else{
                    answer += "L";
                }
            }
            if(i != N - 1) answer += "D";
        }
    // 짝홀
    }else if(N % 2 == 0 && M % 2 == 1){
        for(int i = 0; i < M; ++i){
            for(int j = 0; j < N - 1; ++j){
                if(i % 2 == 0){
                    answer += "D";
                }else{
                    answer += "U";
                }
            }
            if(i != M - 1) answer += "R";
        }
    // 짝짝
    }else{
        int tC = 1000000;
        int tY, tX = 0;
        
        // 지나쳐야할 칸 구하기
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0)){
                    if(board[i][j] < tC){
                        tC = board[i][j];
                        tY = i;
                        tX = j;
                    }
                }
            }
        }

        int line = tY - (tY & 1);

        for(int i = 0; i < N; ++i){
            if(i < line){
                for(int j = 0; j < M - 1; ++j){
                    if(i % 2 == 0){
                        answer += "R";
                    }else{
                        answer += "L";
                    }
                }
                answer += "D";
            }else if(i == line){
                for(int j = 0; j < M - 1; ++j){
                    if(j < tX){
                        if(j % 2 == 0){
                            answer += "DR";
                        }else{
                            answer += "UR";
                        }
                    }else{
                        if(j % 2 == 0){
                            answer += "RD";
                        }else{
                            answer += "RU";
                        }
                    }
                }
                ++i;
            }else{
                answer += "D";
                for(int j = 0; j < M - 1; ++j){
                    if(i % 2 == 1){
                        answer += "R";
                    }else{
                        answer += "L";
                    }
                }
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