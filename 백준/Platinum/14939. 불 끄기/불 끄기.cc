#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

typedef long long ll;

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;


bool origin[10][10];
bool duplication[10][10];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void toggle(int y, int x) {
    duplication[y][x] = !duplication[y][x];

    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || 10 <= ny || nx < 0 || 10 <= nx) continue;
        duplication[ny][nx] = !duplication[ny][nx];
    }
}

void Solve() {
    int answer = INT32_MAX;
    int K = (1 << 10); // 한줄에서 누를 수 있는 경우의 수
    
    for(int k = 0; k < K; ++k){
        // 맵 초기화
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                duplication[i][j] = origin[i][j];
            }
        }

        int cnt = 0;
        // 경우의 수에 맞게 윗줄 토글
        for(int i = 0; i < 10; ++i){
            if(k & (1 << i)){
                toggle(0, i);
                ++cnt;
            }
        }
        // 탐색
        for(int i = 1; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                // 윗줄이 켜져있으면 현재줄 토글
                if(duplication[i-1][j]){
                    toggle(i, j);
                    ++cnt;
                }
            }
        }
        // 마지막줄 체크
        bool flag = false;
        for(int i = 0; i < 10; ++i){
            if(duplication[9][i]) {
                flag = true;
                break;
            }
        }
        if(flag) continue;

        answer = std::min(answer, cnt);
    }

    cout << answer;
}

void Input() {
    char c;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> c;
            if(c == 'O'){
                origin[i][j] = 1;
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
