#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int N;
double K;
int arr[2][7];


void Solve() {
    int answer = 0;

    for(int i = 0; i < 2; ++i){
        for(int j = 1; j < 7; ++j){
            if(arr[i][j] == 0) continue;
            int a = std::ceil(arr[i][j] / K);
            answer += a;
        }
    }

    cout << answer;
}

void Input() {
    cin >> N >> K;

    int s, y;
    for(int i = 0; i < N; ++i){
        cin >> s >> y;
        arr[s][y] += 1;
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

