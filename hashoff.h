#ifndef CPD_TRAB_FINAL_HASHOFF_H
#define CPD_TRAB_FINAL_HASHOFF_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// mudanca qualquer
template<class T>
class hashoff {

public:
    vector<vector<T>> table;
    int M;
    hashoff() {};

    explicit hashoff(int m) {
        this->table.resize(m);
        this->M = m;
    }

    int insert(T s) {
        int h = f(s);
        this->table[h].push_back(s);
        return h;
    }

    int count(T s) {
        int h = f(s);
        int cnt = 0;

        for (T s_ : this->table[h]) {
            cnt++;
            if (s_ == s) return cnt;
        }
        return 0;
    }

private:
    int f(int s) {
        // achei essa hash aqui > shorturl.at/huzNW
        int r = 0;
        r = s;
        r = (((r >> 16) ^ r) * 0x119de1f3) % M;
        r = (((r >> 16) ^ r) * 0x119de1f3) % M;
        r = ((r >> 16) ^ r) % M;
        return r;
    }

    int f(const string &s) {
        int r;
        for (char i : s) {
            if (i == ' ') continue;
            r = (31 * r + (i - 'a')) % M;
        }
        return r;
    }
};

#endif //CPD_TRAB_FINAL_TRIE_H