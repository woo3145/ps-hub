#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::map;
using std::string;

int N;
vector<string> arr;

bool isPalin(int left, int right, bool& check, string& str) {
    while(left < right){
        if(str[left] == str[right]){
            ++left;
            --right;
        }else{
            if(check){
                return false;
            }
            check = true;
            return (isPalin(left + 1, right, check, str) || isPalin(left, right - 1, check, str));
        }
    }
    return true;
}

void Solve() {
    for(auto& s : arr){
        bool check = false;
        bool result = isPalin(0, s.size() - 1, check, s);

        if(!result){
            cout << 2 << '\n';
        }else if(check){
            cout << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
    }
}

void Input() {
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        string str;
        cin >> str;
        arr.push_back(str);
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
