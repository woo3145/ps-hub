#include <iostream>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::string;

int T;

void Input() {
    cin >> T;
}

void Solve() {
    int N;
    cin >> N;
    int max = -1;
    string answer;
    for(int i = 0; i < N; ++i){
        int cost;
        string name;
        cin >> cost >> name;
        if(max < cost){
            max = cost;
            answer = name;
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    for(int i = 0; i < T; ++i){
        Solve();
    }
    
    return 0;
}