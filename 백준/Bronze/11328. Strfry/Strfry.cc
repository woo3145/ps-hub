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

int N;

void Solve() {
    
    for(int i = 0; i < N; ++i){
        string a, b;
        cin >> a >> b;
        if(a.length() != b.length()) {
            cout << "Impossible\n";
            continue;
        }

        vector<int> arr(26, 0);
        for(auto& c : a) arr[c - 'a'] += 1;

        bool flag = true;
        for(auto& c : b) {
            arr[c - 'a'] -= 1;
            if(arr[c - 'a'] < 0){
                cout << "Impossible\n";
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Possible\n";
        }
    }
}

void Input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Input();
    Solve();    
    
    return 0;
}

