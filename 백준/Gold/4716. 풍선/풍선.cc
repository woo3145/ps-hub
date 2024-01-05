#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using std::ios;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;

struct Team {
    int K, DA, DB;
    Team(){};
    ~Team(){};
};

int N, A, B;
vector<Team> teams;

void Input() {
    teams.clear();
    cin >> N >> A >> B;
    teams.resize(N);

    for(auto& t : teams){
        cin >> t.K >> t.DA >> t.DB;
    }
}

void Solve() {
    sort(teams.begin(), teams.end(), [](auto& t1, auto& t2) {
       return std::abs(t1.DB - t1.DA) > std::abs(t2.DB - t2.DA);
    });

    int answer = 0;
    for(auto& p : teams){
        int min, max;
        int gap = (p.DA < p.DB ? A : B) - p.K;
        if(0 <= gap) {
            min = p.K;
            max = 0;
        }else {
            min = (p.DA < p.DB ? A : B);
            max = std::abs(gap);
        }
        if(p.DA < p.DB){
            A -= min;
            B -= max;
        }else{
            A -= max;
            B -= min;
        }

        answer += (p.DA < p.DB ? p.DA : p.DB) * min;
        answer += (p.DA < p.DB ? p.DB : p.DA) * max;
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true){
        Input();
        if(N == 0 && A == 0 && B == 0){
            break;
        }
        Solve(); 
    }
    
    return 0;
}
