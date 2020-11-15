#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream cin("helloworld.txt");
    ofstream cout("G.bin");
    vector<string> c;
    string s;
    while (getline(cin, s)) {
        c.push_back(s);
    }
    int N = 3; // blow-up factor;
    vector<string> ans;
    for (string & x : c) {
        for (int i = 0; i < N; ++i) ans.push_back(x);
    }
    for (string & x : ans) {
        for (char c : x) {
            for (int i = 0; i < N; ++i) cout << c;
        }
        cout << '\n';
    }
}
