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

vector<char> arr;
string S;
 
void Solve() {
    int zero = 0;
    int one = 0;
    for(auto& a : arr){
        if(a == '0') ++one;
        else ++zero;
    }
    cout << std::min(one, zero);
}

void Input() {
    cin >> S;
    char prev = '2';
    char cur;
    for(int i = 0; i < S.length(); ++i){
        cur = S[i];
        if(cur == prev){
            continue;
        }
        arr.push_back(cur);
        prev = cur;
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
