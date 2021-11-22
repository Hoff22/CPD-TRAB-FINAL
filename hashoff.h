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
    int M{};

    hashoff() = default;;

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

    vector<T> getData(){
        vector<T> r;
        for(vector<T> cur : this->table){
            if(cur.size() > 0){
                r.insert(r.end(), cur.begin(), cur.end());
            }
        }
        return r;
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

struct tag {
    string tag_text;
    hashoff<int> players_in_tag = *(new hashoff<int>(100));
};

class hashtag {

public:
    vector<vector<tag>> table;
    int M{};

    explicit hashtag(int m) {
        this->table.resize(m);
        this->M = m;
    }

    int insert(pair<string,int> tag_id) {
        int h = f(tag_id.first);
        // search for an already existing instance of the tag in the hash
        for(auto& t : this->table[h]){
            if(t.tag_text == tag_id.first){
                t.players_in_tag.insert(tag_id.second);
                return h;
            }
        }

        // creates a new tag in the hash with the id
        tag new_tag;
        new_tag.tag_text = tag_id.first;
        new_tag.players_in_tag.insert(tag_id.second);
        this->table[h].push_back(new_tag);
        return h;
    }

    int count(string s) {
        int h = f(s);
        int cnt = 0;

        for (tag s_ : this->table[h]) {
            cnt++;
            if (s_.tag_text == s) return cnt;
        }
        return 0;
    }
    int countID(pair<string,int> tag_id) {
        int h = f(tag_id.first);
        //cout << this->table[h].size() << endl;
        for (tag s_ : this->table[h]) {
            if (s_.tag_text == tag_id.first) return s_.players_in_tag.count(tag_id.second);
        }
        return 0;
    }

    vector<int> getData(string s){
        int h = f(s);
        for (tag s_ : this->table[h]) {
            if (s_.tag_text == s){
                return s_.players_in_tag.getData();
            }
        }
        vector<int> a;
        return a;
    }

private:
   int f(string s) {
       int r;
       for (char i : s) {
           if (i == ' ') continue;
           r = (31 * r + (i - 'a')) % M;
       }
       return r;
   }
};


#endif //CPD_TRAB_FINAL_HASHOFF_H