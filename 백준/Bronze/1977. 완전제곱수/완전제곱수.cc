#include <iostream>

using std::ios;
using std::cout;
using std::cin;

int N, M;

void Input() {
    cin >> N >> M; 
}

void Solve() {
    int square_root = 1;
    int perfect_square_num = square_root * square_root;
    
    int answer = -1;
    int sum = 0;

    while(perfect_square_num <= M) {
        if(N <= perfect_square_num){
            if(answer == -1) answer = perfect_square_num;
            sum += perfect_square_num;
        }
        ++square_root;
        perfect_square_num = square_root * square_root;
    }

    if(answer == -1) {
        cout << -1;
    }else{
        cout << sum << '\n' << answer;
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
