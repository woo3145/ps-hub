#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define lint unsigned long long

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

lint modPow(lint a, lint exp, lint mod);
bool miller_rabin(lint num, lint seed);
bool isPrime(lint num);
void createPalinNums(lint num, vector<lint>& result);

lint N, M;

void Input() {
    cin >> N >> M;
}

void Solve() {
    lint answer = 0;
    vector<lint> palins;
    createPalinNums(M, palins);

    for(const auto& palin : palins){
        if(palin < N) continue;
        if(isPrime(palin)){
            ++answer;
        }
    }
    cout << answer;
}

void createPalinNums(lint num, vector<lint>& result){
    lint ret = num;

    for(int odd = 0; odd < 2; ++odd){
        int cur = 1;
        
        while(true){
            lint palin = cur;
            lint temp = cur;

            if(odd){
                temp /= 10;
            }
            while(temp){
                palin = palin*10 + (temp % 10);
                temp /= 10;
            }
            if(num < palin) break;
            result.push_back(palin);
            ++cur;
        }
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


lint modPow(lint a, lint exp, lint mod){
    lint ret = 1;
    a = a % mod;
    while(exp){
        if(exp & 1) ret = ((__int128_t)ret * a) % mod;
        a = ((__int128_t)a * a) % mod;
        exp >>= 1;
    }

    return ret;
}

bool miller_rabin(lint num, lint seed){
    if(num % seed == 0) return true;

    lint d = num - 1;

    while(true){
        lint tmp = modPow(seed, d, num);

        if(tmp & 1){
            return (tmp != 1 && tmp != num - 1);
        }else if (tmp == num -1){
            return false;
        }
        d >>= 1;
    }
    return true;
}

bool isPrime(lint num){
    if(num < 2 || num % 2 == 0){
        return num == 2;
    }

    vector<lint> seeds({2, 7, 61});

    for(const auto& seed : seeds){
        if(num == seed) return true;
        if(miller_rabin(num, seed)) return false;
    }
    return true;
}