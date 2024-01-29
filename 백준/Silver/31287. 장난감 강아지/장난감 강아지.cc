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

int N, K;
string S;

bool visited[4001][4001];

void Solve() {
    int y = 0;
    int x = 0;
    visited[2000][2000] = true;
    for (char ch : S) {
        if (ch == 'U') y++;
        else if (ch == 'D') y--;
        else if (ch == 'L') x--;
        else if (ch == 'R') x++;
        visited[y + 2000][x + 2000] = true; // 한번 사이클을 돌때 모양 만들기
        // 원점을 지나면 바로 true 반환
        if (x == 0 && y == 0) {
            cout << "YES";
            return;
        };
    }

    int ny = y;
    int nx = x;
    // 2 ~ K번 반복했을때 최종 위치
    for(int i = 1; i < K; ++i){
        int ty = 2000 - ny;
        int tx = 2000 - nx;
        if(ty < 0 || 4000 <= ty || tx < 0 || 4000 <= tx) break;
        if(visited[ty][tx]) {
            cout << "YES";
            return;
        }
        ny += y;
        nx += x;
    }

    cout << "NO";
}

void Input() {
    cin >> N >> K;
    cin >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();
    
    return 0;
}
