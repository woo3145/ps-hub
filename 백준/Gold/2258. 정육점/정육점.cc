#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int N, M;
vector<pair<int, int>> meats;


void Input() {
    cin >> N >> M;
    meats.resize(N);

    for(auto& i : meats){
        cin >> i.first >> i.second;
    }
}

void Solve() {
    sort(meats.begin(), meats.end(), [](const auto& a, const auto& b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    int answer = -1;

    int weight = 0;
    int price = 0;
    for(int i = 0; i < N; ++i){
        weight += meats[i].first;
        if(0 < i && meats[i - 1].second != meats[i].second){
            price = meats[i].second;
        }else{
            price += meats[i].second;
        }

        if(M <= weight && (answer == -1 || price < answer)){
            answer = price;
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
