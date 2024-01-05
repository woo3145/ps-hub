#include <iostream>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::string;

int T;
string paper;

void Input() {
    cin >> paper;
}

bool recur(string& str, int left, int right){
    if(left == right) return true;

    while(left < right){
        if(str[left] == str[right]){
            return false;
        }
        ++left;
        --right;
    }

    return recur(str, left + 1, str.length() - 1);
}

void Solve() {
    if(paper.length() % 2 == 0){
        cout << "NO\n";
        return;
    }

    bool result = recur(paper, 0, paper.length() - 1);

    if(result){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;

    for(int i = 0; i < T; ++i){
        Input();
        Solve(); 
    }
    return 0;
}
