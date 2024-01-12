#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::queue;
using std::pair;
using std::map;


int A, B;
int T;

void Input() {
    cin >> A >> B;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

void Solve() {
    cout << A * B / gcd(A, B) << '\n';
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
