#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define ull unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::string;

int N, M;
pair<ull, bool> table[10];
bool visited[10];
vector<string> strings;

void Input() {
    cin >> N;
    strings.resize(N);

    for(auto& s : strings){
        cin >> s;

        for(int i = 0; i < s.length(); ++i){
            int idx = s[i] - 'A';
            if(i == 0) table[idx].second = true;
            table[idx].first += std::pow(10, s.length() - 1 - i);
        }
    }
}

void Solve() {
    std::sort(table, table + 10);
    
    ull answer = 0;

    for(auto& t : table){
        for(int i = 0; i < 10; ++i){
            if(i == 0 && t.second) continue;
            if(visited[i] == true) continue;
            visited[i] = true;
            answer += t.first * i;
            break;
        }
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve(); 
    
    return 0;
}
