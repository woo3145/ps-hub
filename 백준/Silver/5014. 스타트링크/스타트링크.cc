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

int S, F, G, U, D;
vector<int> arr;

void Solve() {
    queue<int> que;

    que.push(S);
    arr[S] = 0;

    while(!que.empty()){
        int cur = que.front();
        que.pop();

        if(cur == G) {
            cout << arr[cur];
            break;
        }

        if(cur + U <= F && arr[cur + U] == -1) {
            arr[cur + U] = arr[cur] + 1;
            que.push(cur + U);
        };
        if(0 < cur - D && arr[cur - D] == -1) {
            arr[cur - D] = arr[cur] + 1;
            que.push(cur - D);
        }
    }

    if(arr[G] == -1) {
        cout << "use the stairs";
    }
}

void Input() {
    cin >> F >> S >> G >> U >> D;
    arr.assign(F + 1, -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve(); 
    
    return 0;
}

