#include <bits/stdc++.h>

int mode(int v[], int n) {
    int ret = 0, cnt = 0;
    for (int i = 0; i < n; ++i)
        if (std::count(v, v+n, v[i]) > cnt) ret = v[i], cnt = std::count(v, v+n, v[i]);
    return ret;
}

int testa() {
    std::cout << "Enter a space-separated list of numbers (1-9) for unixkcd to test:" << std::endl;
    std::string sa = ""; std::getline(std::cin, sa);
    std::stringstream ssa(sa);
    int a = 0, x = 0;
    for (int i = 0; i < 9; ++i) {
        ssa >> x;
        if (x == 0) break;
        if (x < 1 || x > 9) {
            std::cout << "You didn't enter a space-separated list of numbers (1-9)!" << std::endl;
            return -1;
        }
        a |= (1<<x);
    }
    return a;
}

int testb() {
    std::cout << "Enter a space-separated list of numbers (1-9) for BigChonk to test:" << std::endl;
    std::string sb = ""; std::getline(std::cin, sb);
    std::stringstream ssb(sb);
    int b = 0, x = 0;
    for (int i = 0; i < 9; ++i) {
        ssb >> x;
        if (x == 0) break;
        if (x < 1 || x > 9) {
            std::cout << "You didn't enter a space-separated list of numbers (1-9)!" << std::endl;
            return -1;
        }
        b |= (1<<x);
    }
    return b;
}

bool test() {
    std::cout << "Round 1" << std::endl;
    int a = testa(), b = testb();
    if (a == -1 || b == -1) {
        std::cout << "You lost!" << std::endl;
        return 0;
    }

    int p[10];
    for (int i = 0; i < 10; ++i) p[i] = -1;
    for (int i = 1; i <= 9; ++i) p[i] = ((1&(a>>i))<<1)+(1&(b>>i));

    int m = mode(p, 10);
    if (m == 3) {
        std::cout << "unixkcd died!" << std::endl;
        std::cout << "BigChonk died!" << std::endl;
        std::cout << "You lost!" << std::endl;
        return 0;
    }
    else if (m == 2) {
        std::cout << "unixkcd died!" << std::endl;
        std::cout << "BigChonk survived!" << std::endl;
        
        std::cout << "Round 2" << std::endl;
        int b = testb();
        if (b == 0 || (b & (b-1))) std::cout << "BigChonk died!" << std::endl;
        else std::cout << "BigChonk survived!" << std::endl;
        std::cout << "You lost!" << std::endl;
        return 0;
    }
    else if (m == 1) {
        std::cout << "unixkcd survived!" << std::endl;
        std::cout << "BigChonk died!" << std::endl;
        
        std::cout << "Round 2" << std::endl;
        int a = testa();
        if (a == 0 || (a & (a-1))) std::cout << "unixkcd died!" << std::endl;
        else std::cout << "unixkcd survived!" << std::endl;
        std::cout << "You lost!" << std::endl;
        return 0;
    }
    else {
        std::cout << "unixkcd survived!" << std::endl;
        std::cout << "BigChonk survived!" << std::endl;

        std::cout << "Round 2" << std::endl;
        int a = testa(), b = testb();
        if (a == -1 || b == -1) {
            std::cout << "You lost!" << std::endl;
            return 0;
        }
        
        int np[10];
        for (int i = 0; i < 10; ++i) np[i] = -1;
        for (int i = 1; i <= 9; ++i)
            if (p[i] == 0) np[i] = ((1&(a>>i))<<1)+(1&(b>>i));
        
        if (std::count(p, p+10, 1) != 2 || std::count(p, p+10, 2) != 2 || std::count(p, p+10, 3) != 1) {
            std::cout << "You lost!" << std::endl;
            return 0;
        }

        if (std::count(np, np+10, -1) != 6) {
            std::cout << "You lost!" << std::endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            if (std::count(np, np+10, i) != 1 || p[std::find(np, np+10, i)-np] != 0) {
                std::cout << "You lost!" << std::endl;
                return 0;
            }
        }
        
        std::cout << "unixkcd died!" << std::endl;
        std::cout << "BigChonk died!" << std::endl;
        
        std::cout << "What is the answer?" << std::endl;
        int gs; std::cin >> gs;
        if (gs == std::find(np, np+10, 3)-np) {
            std::cout << "You won!" << std::endl;
            return 1;
        }
        else {
            std::cout << "You lost!" << std::endl;
            return 0;
        }
    }
}

void done() {
    std::cout << "You completed problem I! Use \"toohard\" to unlock the zip." << std::endl;
}

int main() {
    while (!test()) {
        std::cout << "Play again? (y/n)" << std::endl;
        std::string s = ""; std::cin >> s;
        if (s == "n") return 0;
        std::cin.ignore(2, '\n');
    }
    done();
}
