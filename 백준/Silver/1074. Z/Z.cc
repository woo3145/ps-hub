#include <iostream>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;

int N, R, C;

int recur(int size, int r, int c){
    if(size == 0) return 0;

    int half = size / 2;

    if(r < half && c < half) return recur(half, r, c);
    else if (r < half && half <= c) return half * half + recur(half, r, c - half);
    else if (half <= r && c < half) return half * half * 2 + recur(half, r - half, c);
    else return half * half * 3 + recur(half, r - half, c - half);
}

void Solve() {
    cout << recur(std::pow(2, N), R, C);
}

void Input() {
    cin >> N >> R >> C;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}