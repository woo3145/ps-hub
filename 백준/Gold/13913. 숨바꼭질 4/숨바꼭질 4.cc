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

struct Pos {
    int x, cost;
};

int N, K;

vector<int> arr;

void Solve() {
    queue<Pos> que;
    
    que.push({N, 0});
    arr[N] = N;
    while(!que.empty()){
        Pos cur = que.front();
        que.pop();

        if(cur.x == K){
            cout << cur.cost << '\n';
            break;
        }
        if(cur.x * 2 <= 100000 && arr[cur.x * 2] == -1) {
            que.push({cur.x * 2, cur.cost + 1});
            arr[cur.x * 2] = cur.x;
        }
        if(0 < cur.x && arr[cur.x - 1] == -1) {
            que.push({cur.x - 1, cur.cost + 1});
            arr[cur.x - 1] = cur.x;
        }
        if(cur.x < 100000 && arr[cur.x + 1] == -1) {
            que.push({cur.x + 1, cur.cost + 1});
            arr[cur.x + 1] = cur.x;
        }
        
    }

    if(N == K){
        cout << N;
        return;
    }

    vector<int> answer;
    int cur = arr[K];
    answer.push_back(K);
    while(true){
        if(cur == arr[cur]) break;
        answer.push_back(cur);
        cur = arr[cur];
    }
    answer.push_back(N);

    while(!answer.empty()){
        cout << answer.back() << ' ';
        answer.pop_back();
    }
}

void Input() {
    cin >> N >> K;
    arr.assign(100001, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve(); 
    
    return 0;
}

