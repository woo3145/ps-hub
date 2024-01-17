#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N;
vector<int> arr;

void Solve() {
    std::sort(arr.begin(), arr.end());

    for(auto& a : arr){
        cout << a << '\n';
    }
}

void Input() {
    cin >> N;
    arr.resize(N);

    for(auto& n : arr){
        cin >> n;
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