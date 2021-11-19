#include "definitions.h"
#include "hashoff.cpp"

using namespace std;

float ratings[N];
int count[N];
int positions[N]; // bitmask 21 positions

string names[N];

struct tag {
    string str;
    hashoff<int> players = hashoff<int>(30000);
};

int main() {

    hashoff<string> superset(100);

    superset.insert("abobora");

    cout << "o set tem abgfhj?" << superset.count("abgfhj") << endl;
    cout << "o set tem abobora?" << superset.count("abobora") << endl;

    return 0;
}