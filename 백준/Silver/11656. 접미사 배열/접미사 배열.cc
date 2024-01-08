#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string str;

void Input() {
   cin >> str;
}

void Solve() {
    vector<string> arr;

    for(int i = 0; i < str.length();++i){
        arr.push_back(str.substr(i));
    }
    
    std::sort(arr.begin(), arr.end());

    for(auto& s : arr){
        cout << s << '\n';
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
