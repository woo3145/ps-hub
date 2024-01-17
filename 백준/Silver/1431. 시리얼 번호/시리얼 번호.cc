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

int N;
vector<string> arr;

int sum(string& s){
    int ret = 0;
    for(char& c : s){
        int result = c - '0';
        if(result < 10){
            ret += result;
        }
    }
    return ret;
}

void Solve() {
    
    std::sort(arr.begin(), arr.end(), [](string& a, string& b) {
        if(a.length() != b.length()){
            return a.length() < b.length();
        }
        int aS = sum(a);
        int bS = sum(b);
        if(aS == bS) {
            return a < b;
        }
        return aS < bS;
    });

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
