#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::pair;
using std::queue;

int N, K;
int MAX_N = 500001;

vector<int> arr;
int visited[2][500001];


void Solve() {
    queue<pair<int, int>> que;

    que.push({N, 0});
    visited[0][N] = true;

    while(!que.empty()){
        pair<int,int> cur = que.front();
        que.pop();

        int brother = K + cur.second * (cur.second + 1) / 2;

        if(MAX_N <= brother) {
            cout << -1;
            return;
        }
        
        if(visited[cur.second % 2][brother]) {
            cout << cur.second;
            return;
        }

        int nextSec = cur.second + 1;
        if(0 <= cur.first - 1 && !visited[nextSec % 2][cur.first - 1]) {
            que.push({cur.first - 1, cur.second + 1});
            visited[nextSec % 2][cur.first - 1] = true;
        }
        if(cur.first + 1 < MAX_N && !visited[nextSec % 2][cur.first + 1]) {
            que.push({cur.first + 1, cur.second + 1});
            visited[nextSec % 2][cur.first + 1] = true;
        }
        if(cur.first * 2 < MAX_N && !visited[nextSec % 2][cur.first * 2]) {
            que.push({cur.first * 2, cur.second + 1});
            visited[nextSec % 2][cur.first * 2] = true;
        }
    }

    cout << -1;
}

void Input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve(); 
    
    return 0;
}

