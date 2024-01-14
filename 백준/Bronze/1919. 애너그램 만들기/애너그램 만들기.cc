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

string A, B;

void Solve() {
    vector<int> arr(26, 0);

    for(auto& c : A) arr[c - 'a'] += 1;
    for(auto& c : B) arr[c - 'a'] -= 1;

    int answer = 0;
    for(int i = 0; i < 26; ++i){
        answer += std::abs(arr[i]);
    }
    cout << answer;
}

void Input() {
    cin >> A >> B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}

