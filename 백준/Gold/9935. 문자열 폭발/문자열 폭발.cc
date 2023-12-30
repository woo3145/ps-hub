#include <iostream>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

string S, C;

void Input() {
    cin >> S >> C;    
}
void Solve() {
    vector<char> stack;

    for(const auto& s : S){
        stack.push_back(s);
        if(stack.size() < C.size()) continue;
        if(stack.back() != C.back()) continue;
        int idx = C.length() - 1;
        bool flag = true;
        while(0 <= idx){
            if(stack[stack.size() - 1 - idx] != C[C.length() - 1 - idx]){
                flag = false;
                break;
            }
            --idx;
        }

        if(flag){
            for(int i = 0; i < C.length(); ++i) stack.pop_back();
        }
    }

    if(stack.empty()){
        cout << "FRULA";
    }else{
        for(auto& c : stack) cout << c;
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
