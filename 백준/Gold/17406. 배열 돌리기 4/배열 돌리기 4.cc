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
using std::queue;

struct Command {
    int r, c, s;
};

int N, M, K;
int origin[101][101];
int board[101][101];
int temp[101][101];
vector<Command> commands;

void print() {
    cout << "************** \n";
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void rotate(int y1, int x1, int y2, int x2){
    // 윗줄
    for(int i = x2; x1 < i; --i){
        temp[y1][i] = board[y1][i-1];
    }
    // 아래줄
    for(int i = x1; i < x2; ++i){
        temp[y2][i] = board[y2][i+1];
    }
    // 오른쪽
    for(int i = y2; y1 < i; --i){
        temp[i][x2] = board[i-1][x2];
    }
    // 왼쪽
    for(int i = y1; i < y2; ++i){
        temp[i][x1] = board[i + 1][x1];
    }

    for(int i = x1; i <= x2; ++i) {
        board[y1][i] = temp[y1][i];
        board[y2][i] = temp[y2][i];
    };
    for(int i = y1; i <= y2; ++i){
        board[i][x1] = temp[i][x1];
        board[i][x2] = temp[i][x2];
    }
}

void rotateAll(int r, int c, int size){
    while(0 < size){
        rotate(r - size, c - size, r + size, c + size);
        --size;
    }
}

void Solve() {
    int answer = INT32_MAX;

    vector<int> order;
    for(int i = 0; i < K;++i){
        order.push_back(i);
    }
    do{ 
        // 보드판 초기화
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                board[i][j] = origin[i][j];
            }
        }
        for(int i = 0; i < K; ++i){
            rotateAll(commands[order[i]].r - 1, commands[order[i]].c - 1, commands[order[i]].s);
        }
        for(int y = 0; y < N; ++y){
            int sum = 0;
            for(int x = 0; x < M; ++x){
                sum += board[y][x];
            }
            answer = std::min(answer, sum);
        }
    }while(std::next_permutation(order.begin(), order.end()));


    cout << answer;
}


void Input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            cin >> origin[i][j];
        }
    }

    commands.resize(K);
    for(auto& k : commands){
        cin >> k.r >> k.c >> k.s;
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
