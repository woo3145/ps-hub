#include <iostream>

using std::ios;
using std::cout;
using std::cin;

int N;

void Input() {
    cin >> N;
}

void Solve() {
    int changes = 1000 - N;
    int coins[6] = {500, 100, 50, 10, 5, 1};

    int answer = 0;

    for(int i = 0; i < 6; ++i){
        int cnt = changes / coins[i];
        changes = changes % coins[i];
        answer += cnt;
    }

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
