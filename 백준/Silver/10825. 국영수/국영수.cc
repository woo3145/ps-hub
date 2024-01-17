#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::queue;
using std::string;
using std::map;

struct Student {
    string name;
    int a, b, c;
};

int N;
vector<Student> arr;

void Solve() {
    std::sort(arr.begin(), arr.end(), [](const Student& a, const Student& b){
        if(a.a == b.a && a.b == b.b && a.c == b.c) {
            return a.name < b.name;
        }
        if(a.a == b.a && a.b == b.b){
            return a.c > b.c;
        }
        if(a.a == b.a){
            return a.b < b.b;
        }
        return a.a > b.a;
    });

    for(auto& a : arr){
        cout << a.name << '\n';
    }
}

void Input() {
    cin >> N;
    arr.resize(N);
    for(auto& a : arr){
        cin >> a.name >> a.a >> a.b >> a.c;
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