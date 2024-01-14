#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string S;

void Solve() {
    vector<int> arr(26, 0);

    for(auto& c : S){
        arr[c - 'a'] += 1;
    }

    for(auto& c : arr){
        cout << c << ' ';
    }
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

