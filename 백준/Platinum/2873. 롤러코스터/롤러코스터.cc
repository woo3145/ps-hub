#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;

// 3 3
// 5 1 3
// 2 4 8
// 1 1 2

int N, M;
vector<vector<int>> board;

//
// 짝짝
// 1 4 11 ?        
// 8 6 ?  1



// 1 4 1 5        
// 4 6 3  6
// 4 4 11 4     
// 2 6 2  1

// 홀수가 섞여있으면 짝수쪽으로 먼저 이동 시 모든칸 방문 가능
// 짝홀
// 1 4 11 6 7
// 8 5 4  6 1       
// 1 4 11 6 7
// 8 5 4  6 1

// 홀짝
// 1 4 11 20        
// 8 6 3  1
// 1 4 11 1

// 어느쪽으로 가든 모든칸 방문 가능
// 홀홀
// 1 4 11       
// 8 6 3  
// 1 4 1

int maxCost = 0;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char ds[4] = {'U', 'R', 'D', 'L'};

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
    // 짝짝 dfsxxxxxxxxx
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
        // 1 x 5 x 2 x     
        // x 6 x 1 x 5
        // 1 x 4 x 6 x     (3, 2)  2
        // x 6 x 1 x 2     D R U R (R) D R U R D
        // 8 x 5 x 5 x     (2, 1)  2
        // x 6 x 1 x 2     D R (R) U R D R U R D

        for(int i = 0; i < N; ++i){
            // 타겟이 존재하는 2줄 처리
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
                bool flag = true;
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


// 4 4
// 1 1 4 5        
// 4 6 3  6
// 4 4 11 4     
// 2 6 2  1