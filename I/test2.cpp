#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int mode(vector<int> v) {
    int ret = 0, cnt = 0;
    for (int x : v)
        if (count(begin(v), end(v), x) > cnt) ret = x;
    return ret;
}

int testa() {
    cout << "Enter a space-separated list of numbers (1-9) for unixkcd to test:" << endl;
    string sa; getline(cin, sa);
    stringstream ssa(sa);
    int a = 0, x;
    while (ssa >> x) {
        if (x < 1 || x > 9) {
            cout << "You didn't enter a space-separated list of numbers (1-9)!" << endl;
            return -1;
        }
        a |= (1<<x);
    }
    return a;
}

int testb() {
    cout << "Enter a space-separated list of numbers (1-9) for BigChonk to test:" << endl;
    string sb; getline(cin, sb);
    stringstream ssb(sb);
    int b = 0, x;
    while (ssb >> x) {
        if (x < 1 || x > 9) {
            cout << "You didn't enter a space-separated list of numbers (1-9)!" << endl;
            return -1;
        }
        b |= (1<<x);
    }
    return b;
}

bool test() {
    cout << "Round 1" << endl;
    int a = testa(), b = testb();
    if (a == -1 || b == -1) {
        cout << "You lost!" << endl;
        return 0;
    }

    vector<int> p(10, -1);
    for (int i = 1; i <= 9; ++i) p[i] = ((1&(a>>i))<<1)+(1&(b>>i));

    int m = mode(p);
    if (m == 3) {
        cout << "unixkcd died!" << endl;
        cout << "BigChonk died!" << endl;
        cout << "You lost!" << endl;
        return 0;
    }
    else if (m == 2) {
        cout << "unixkcd died!" << endl;
        cout << "BigChonk survived!" << endl;
        
        cout << "Round 2" << endl;
        int b = testb();
        if (b) cout << "BigChonk survived!" << endl;
        else cout << "BigChonk died!" << endl;
        cout << "You lost!" << endl;
        return 0;
    }
    else if (m == 1) {
        cout << "unixkcd survived!" << endl;
        cout << "BigChonk died!" << endl;
        
        cout << "Round 2" << endl;
        int a = testa();
        if (a) cout << "unixkcd survived!" << endl;
        else cout << "unixkcd died!" << endl;
        cout << "You lost!" << endl;
        return 0;
    }
    else {
        cout << "unixkcd survived!" << endl;
        cout << "BigChonk survived!" << endl;

        cout << "Round 2" << endl;
        int a = testa(), b = testb();
        if (a == -1 || b == -1) {
            cout << "You lost!" << endl;
            return 0;
        }

        vector<int> np(10, -1);
        for (int i = 1; i <= 9; ++i)
            if (p[i] == 0) np[i] = ((1&(a>>i))<<1)+(1&(b>>i));
        
        for (int i = 0; i < 4; ++i) {
            if (count(begin(np), end(np), i) != 1 || p[find(begin(np), end(np), i)-begin(np)] != 0) {
                cout << "You lost!" << endl;
                return 0;
            }
        }
        
        cout << "unixkcd died!" << endl;
        cout << "BigChonk died!" << endl;
        
        cout << "What is the answer?" << endl;
        int gs; cin >> gs;
        if (gs == find(begin(np), end(np), 3)-begin(np)) {
            cout << "You won!" << endl;
            return 1;
        }
        else {
            cout << "You lost!" << endl;
            return 0;
        }
    }
}

void done() {
    cout << "You completed problem I! The answer is \"toohard\"." << endl;
}

int main() {
    while (!test()) {
        cout << "Play again? (y/n)" << endl;
        string s; cin >> s;
        if (s == "n") return 0;
        cin.ignore(2, '\n');
    }
    done();
}
