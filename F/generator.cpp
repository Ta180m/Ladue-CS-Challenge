#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout("test.txt");
    for (int i = 1; i <= 1e4; ++i) {
        if (i == 9000) {
            for (int j = 0; j < 84; ++j) cout << char(rand()%26+'a');
            cout << "answerjavascript\n";
        }
        else {
            for (int j = 0; j < 100; ++j) cout << char(rand()%26+'a');
            cout << '\n';
        }
    }
}
