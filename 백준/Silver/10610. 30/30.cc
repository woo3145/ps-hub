#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::string;

string N;

void Input() {
    cin >> N;
}

void Solve() {
    int sum = 0;
    std::sort(N.begin(), N.end(), std::greater<>());

    for(int i = 0; i < N.length(); ++i){
        sum += N[i] - '0';
    }

    if(sum % 3 == 0 && N[N.length() - 1] == '0'){
        cout << N;
    }else{
        cout << -1;
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
