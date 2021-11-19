#include "definitions.h"

using namespace std;

template<class T>
class hashoff {
    vector<vector<T>> table;
    int M;
public:
    hashoff(int m) {
        this->table.resize(m);
        this->M = m;
    }

    void insert(T s) {
        int h = f(s);

        this->table[h].push_back(s);
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

    int f(string s) {
        int r;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            r = (31 * r + (s[i] - 'a')) % M;
        }
        return r;
    }
};