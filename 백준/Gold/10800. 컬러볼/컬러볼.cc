#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

struct Ball {
    int idx;
    int color;
    int weight;
};

int N;
vector<Ball> balls;


void Input() {
    cin >> N;
    balls.resize(N);
    int i = 0;
    for(auto& b : balls){
        cin >> b.color >> b.weight;
        b.idx = i;
        ++i;
    }
}

void Solve() {
    std::sort(balls.begin(), balls.end(),[](const Ball& a, const Ball& b){
        if(a.weight == b.weight) return a.color < b.color;
        return a.weight < b.weight;
    });
    vector<int> answer;
    vector<int> cache;
    answer.assign(N, 0);
    cache.assign(N, 0);
    int sum = 0;
    int j = 0;
    for(int i = 0; i < N; ++i){
        while(balls[j].weight < balls[i].weight){
            sum += balls[j].weight;
            cache[balls[j].color] += balls[j].weight;
            ++j;
        }
        answer[balls[i].idx] = sum - cache[balls[i].color];
    }
    
    for(int i = 0; i < N; ++i){
        cout << answer[i] << '\n';
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
