#include <iostream>
#include <algorithm>

#define ull unsigned long long

using std::ios;
using std::cout;
using std::cin;

ull X, Y, W, S;

// 1000 5 10
// 6 9 33 59 100 341 431 444 565 857

void Input() {
    cin >> X >> Y >> W >> S;
}

// 25 18 7 11

void Solve() {
    ull answer = 0;

    // 최대한 대각선으로 이동하여 한쪽을 0으로 만듬
    ull crossCost = std::min(W + W, S);
    ull possibleCross = std::min(X, Y);

    answer += crossCost * possibleCross;
    X -= possibleCross;
    Y -= possibleCross;

    // 어느쪽이 홀수일 경우 한번은 직선으로 움직여야함
    if(X && X % 2 == 1) {
        answer += W;
        X -= 1;
    }
    if(Y && Y % 2 == 1) {
        answer += W;
        Y -= 1;
    }

    // 2칸을 이동하는경우 (대각 + 대각) or (직선 + 직선) 중 비용이 적은 방법으로 이동
    ull minCost = std::min(W + W, S + S);
    answer += minCost * (X / 2);
    answer += minCost * (Y / 2);

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
