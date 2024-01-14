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

string S;

void Solve() {
    vector<int> arr(10, 0);

    for(auto& c : S){
        arr[c - '0'] += 1;
    }

    int answer = 1;
    for(int i = 0; i < 10; ++i){
        if(i == 6 || i == 9) continue;
        answer = std::max(answer, arr[i]);
    }

    cout << std::max(answer, (arr[6] + arr[9] + 1) / 2);
}

void Input() {
    cin >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}

