#include <iostream>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::pow;

int T;
int X, Y, X2, Y2;
int N;
int CX, CY, R;

void Input() {
    cin >> X >> Y >> X2 >> Y2 >> N;
}

bool checkInsidePoint (int cx, int cy, int r, int x, int y){
    return pow(cx - x, 2) + pow(cy - y, 2) <= pow(r, 2);
}

void Solve() {
    int answer = 0;
    for(int i = 0; i < N; ++i){
        cin >> CX >> CY >> R;

        int result_1 = checkInsidePoint(CX, CY, R, X, Y);
        int result_2 = checkInsidePoint(CX, CY, R, X2, Y2);

        if(result_1 && result_2) continue; // 둘다 원안
        if(!result_1 && !result_2) continue; // 둘다 원밖
        ++answer;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int i = 0; i < T; ++i){
        Input();
        Solve();
    }
    
    return 0;
}
