#include <bits/stdc++.h>
using namespace std;

bool is_prime(int i) {
    if (i <= 1) return 0;
    for (int j = 2; j*j <= i; ++j) {
        if (i%j == 0) return 0;
    }
    return 1;
}

int main() {
    string ans = "whosaidthegenerationofrandomnumbersistooimportanttobelefttochance";
    
    int j = 0;
    for (int i = 0; i <= 315; ++i) {
        if (is_prime(i)) cout << ans[j++];
        else cout << char(rand()%26+'a');
    }
}
