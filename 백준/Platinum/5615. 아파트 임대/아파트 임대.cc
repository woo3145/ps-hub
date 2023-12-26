#include <iostream>
#include <vector>

#define ull unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;

ull modPow(ull a, ull p, ull m);
bool miller_rabin(ull num, ull seed);
bool isPrime(ull num);

int N;

void Input() {
    cin >> N;
}


void Solve() {
    int answer = 0;
    for(int i = 0; i < N; ++i){
        ull S;
        cin >> S;
        S = S * 2 + 1;
        if(isPrime(S)) {
            ++answer;
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

ull modPow(ull base, ull p, ull mod) {
    ull ret = 1;

    while(p) {
        if(p & 1) ret = (ret * base) % mod;
        base = (base * base) % mod;
        p >>= 1;
    }

    return ret;
}

// true: 합성수
bool miller_rabin(ull num, ull seed){
    if(num % seed == 0) return num == seed;

    ull d = num - 1;
    while (d % 2 == 0) d /= 2;

    ull tmp = modPow(seed, d, num);
    if (tmp == 1 || tmp == num - 1) return false;

    while (d != num - 1) {
        tmp = (tmp * tmp) % num;
        d *= 2;

        if (tmp == 1) return true;
        if (tmp == num - 1) return false;
    }

    return true;
}

bool isPrime(ull num){
    if(num < 2 || num % 2 == 0){
        return num == 2;
    }

    vector<ull> seeds = {2, 3, 5, 61};

    for(const auto& seed : seeds){
        if(num == seed) return true;

        if(miller_rabin(num, seed)) return false;
    }  

    return true;
}