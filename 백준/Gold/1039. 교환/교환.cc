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
using std::max;

int K;
string S;

void swap(string& str, int i, int j){
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void Input() {
    cin >> S >> K;
}

void Solve() {
    int answer = -1;
    queue<pair<string, int>> q;
    map<string, bool> cache;

    q.push({S, 0});
    int prev = 0;
    while(!q.empty()){
        pair<string, int> cur = q.front();
        q.pop();

        if(prev < cur.second){
            cache.clear();
            prev = cur.second;
        }
        if(K <= cur.second) {
            q.push(cur);
            break;
        };

        if(cache.find(cur.first) != cache.end()) continue;
        cache.insert({cur.first, true});

        for(int i = 0; i < S.length(); ++i){
            for(int j = i + 1; j < S.length(); ++j){
                if(i == 0 && cur.first[j] == '0') continue;
                swap(cur.first, i, j);
                q.push({cur.first, cur.second + 1});
                swap(cur.first, i, j);
            }
        }
    }

    while(!q.empty()){
        answer = max(answer, std::stoi(q.front().first));
        q.pop();
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
