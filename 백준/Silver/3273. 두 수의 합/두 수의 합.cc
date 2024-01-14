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

int N, X;
vector<int> arr;
bool cache[1000001];

void Solve() {
    int answer = 0;
    for(auto& n : arr){
        int rest = X - n;
        if(0 <= rest && rest <= 1000000 && cache[rest]) {
            ++answer;
        }
    }

    cout << answer / 2;
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& n : arr){
        cin >> n;
        cache[n] = true;
    }
    cin >> X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}

