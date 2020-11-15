#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int first_index(ll & k, int n) {
    if (n == 1) return 0;
    n--;
    int first_num_index;
    ll n_partial_fact = n;
    while (k >= n_partial_fact && n > 1) {
        n_partial_fact = n_partial_fact * (n - 1);
        n--;
    }
    first_num_index = k / n_partial_fact;
    k %= n_partial_fact;
    return first_num_index;
}

vector<int> kth_perm(int n, ll k) {
    vector<int> ans;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
 
    auto it = begin(s);
    --k; 
    for (int i = 0; i < n; i++) {
        int index = first_index(k, n - i);
        advance(it, index);
        ans.push_back(*it);
        s.erase(it);
        it = begin(s);
    }
    return ans;
}

int main() {
    ll n = 9, k = 1e5;
    vector<int> ans = kth_perm(n, k);
    for (int x : ans) cout << x << ' ';
    return 0;
} 
