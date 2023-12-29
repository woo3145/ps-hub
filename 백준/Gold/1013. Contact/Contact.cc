#include <iostream>
#include <vector>
#include <string>
#include <regex>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

int N;
vector<string> arr;

void Input() {
    cin >> N;
    arr.reserve(N);
    for(int i = 0; i < N; ++i){
        string a;
        cin >> a;
        arr.push_back(a);
    }
}

void Solve() {
    for(const auto& s : arr){
        cout << (std::regex_match(s, std::regex("(100+1+|01)+")) ? "YES" : "NO") << '\n';
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
