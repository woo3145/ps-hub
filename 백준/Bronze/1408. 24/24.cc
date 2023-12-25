#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::ios;
using std::cout;
using std::cin;
using std::vector;
using std::string;

vector<string> split(string input, const string& delimiter);

string start, end;

void Input() {
    cin >> start >> end;
}

void Solve() {
    vector<string> _s, _e;

    _s = split(start, ":");
    _e = split(end, ":");

    vector<int> s(_s.size()), e(_e.size());

    std::transform(_s.begin(), _s.end(), s.begin(), [](const string& str) {
        return std::stoi(str);
    });
    std::transform(_e.begin(), _e.end(), e.begin(), [](const string& str) {
        return std::stoi(str);
    });

    int hours = e[0] - s[0];
    int minutes = e[1] - s[1];
    int seconds = e[2] - s[2];
    if(seconds < 0) {
        seconds += 60;
        minutes -= 1;
    } 
    if(minutes < 0){
        minutes += 60;
        hours -= 1;
    }
    if(hours < 0) {
        hours += 24;
    }
    cout << (hours < 10 ? "0" : "") << hours << ":";
    cout << (minutes < 10 ? "0" : "") << minutes << ":" ;
    cout << (seconds < 10 ? "0" : "") << seconds;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    Input();
    Solve();
    
    return 0;
}

vector<string> split(string input, const string& delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token;
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);

    return ret;
}