#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;

int N, M;

void Input() {
    cin >> N >> M;
}

// 0 0 2 0 0 0 2 0 0
// 1 0 0 0 2 0 0 0 x

// 1 2 3 4 5 6 7 8 9

// -----------------

// 0 0 0 0 0 2 0 2 0
// 0 0 2 0 0 0 0 0 0
// 1 0 0 0 2 0 2 0 2

// 0 2 0 2 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 1 0 2 0 x 0 0 0 0

// 1 2 3 4 5 6 7 8 9

// 4칸 이상 이동할때 4가지 방법을 모두 써야함

void Solve() {
    if(N == 1) {
        cout << 1;
    }else if(N == 2){
        int cnt = std::floor((M + 1) / 2);
        cout << (4 < cnt ? 4 : cnt);
    }else {
        if(6 < M) {
            cout << 4 + (M-6);
        }else {
            cout << (4 <= M ? 4 : M);
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
