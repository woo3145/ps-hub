#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::vector;

int N, M;
vector<int> l_books;
vector<int> r_books;

void Input() {
    cin >> N >> M;
    int pos;

    for(int i = 0; i < N; ++i){
        cin >> pos;
        if(pos < 0) {
            l_books.push_back(-pos);
        }else{
            r_books.push_back(pos);
        }
    }
}

void Solve() {
    int answer = 0;
    int maxDist = 0;
    
    std::sort(l_books.rbegin(), l_books.rend());
    std::sort(r_books.rbegin(), r_books.rend());
    
    for(int i = 0; i < l_books.size(); i += M){
        if(i == 0) maxDist = maxDist < l_books[0] ? l_books[0] : maxDist;
        answer += l_books[i] * 2;
    }
    
    for(int i = 0; i < r_books.size(); i += M){
        if(i == 0) maxDist = maxDist < r_books[0] ? r_books[0] : maxDist;
        answer += r_books[i] * 2;
    }

    cout << answer - maxDist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
