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

int N, M;
map<string, vector<string>> groups;
map<string, string> team;

void Solve() {
    int K;
    string name;
    for(int i = 0; i < M; ++i){
        cin >> name >> K;

        if(K == 0){
            for(auto& n : groups[name]){
                cout << n << '\n';
            }
        }else{
            cout << team[name] << '\n';
        }
    }
}

void Input() {
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i){
        string teamName;
        int K;
        cin >> teamName >> K;
        groups[teamName] = vector<string>();
        groups[teamName].reserve(K);
        string name;
        for(int j = 0; j < K; ++j){
            cin >> name;
            groups[teamName].push_back(name);
            team[name] = teamName;
        }
        std::sort(groups[teamName].begin(), groups[teamName].end());
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
