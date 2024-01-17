#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;

long long N;
vector<long long> arr;

long long reverseNum(long long a){
    long long ret = 0;
    while(0 < a){
        ret *= 10;
        ret += a % 10;
        a /= 10;
    }
    return ret;
}

void Solve() {
    std::sort(arr.begin(), arr.end());

    for(auto& a : arr){
        cout << a << '\n';
    }
}

void Input() {
    cin >> N;
    arr.resize(N);
    long long tmp;
    for(auto& n : arr){
        cin >> tmp;
        n = reverseNum(tmp);
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