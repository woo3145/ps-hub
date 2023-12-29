#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::sort;

bool isPrefix(const string& prefix, const string& str);

int N;
vector<string> arr;

// 6
// a
// b
// cba
// cbc
// cbb
// ccc

void Input() {
    cin >> N;
    arr.assign(N, "");
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
    
}
void Solve() {
    sort(arr.begin(), arr.end());
    
    vector<string> stack;
    for(int i = 0; i < N; ++i){
        if(stack.empty()) {
            stack.push_back(arr[i]);
            continue;
        }

        if(isPrefix(stack[stack.size() - 1], arr[i])){
            stack.pop_back();
        }
        stack.push_back(arr[i]);
    }

    cout << stack.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}

bool isPrefix(const string& prefix, const string& str){
    for(int i = 0; i < prefix.length(); ++i){
        if(prefix[i] != str[i]) return false;
    }
    return true;
}