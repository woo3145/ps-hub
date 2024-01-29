#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;

int N;
vector<vector<int>> rounds;
vector<int> order;

int move(int* board, int cnt){
    int score = 0;
    
    for(int i = 3; 0 < i; --i){
        if(board[i] == -1) continue;
        
        // 홈으로 들어옴
        if(4 <= i + cnt) {
            board[i] = -1;
            ++score;
        }else{
            board[i + cnt] = board[i];
            board[i] = -1;
        }
    }

    return score;
}

int simulate(){
    int score = 0;
    int curIdx = 0;
    
    for(auto& curRound : rounds){
        int outCount = 0;
        int board[4] = {-1, -1, -1, -1};
        while(outCount < 3){
            int cur = curRound[order[curIdx]];
            // 아웃
            if(cur == 0) {
                ++outCount;
            }else if(cur == 4){
                for(int i = 1; i < 4; ++i){
                    if(board[i] == -1) continue;
                    board[i] = -1;
                    ++score;
                }
                ++score;
            }else {
                // 1, 2, 3루타
                score += move(board, cur);
                board[cur] = order[curIdx];
            }
            ++curIdx;
            curIdx %= 9;
        }
    }
    return score;
}

void Solve() {
    int answer = 0;
    do{
        if(0 == order[3]) {
            int score = simulate();
            answer = std::max(answer, score);
        };
    }while(std::next_permutation(order.begin(), order.end()));
    cout << answer;
}

void Input() {
    cin >> N;
    rounds.resize(N, vector<int>(9, 0));
    for(auto& r : rounds){
        for(auto& n : r){
            cin >> n;
        }
    }

    for(int i = 0; i < 9; ++i){
        order.push_back(i);
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
