#include <iomanip>
#include <bitset>
#include "hashoff.h"
#include "definitions.h"
#include "trie.h"

#define N 300000 // max player ID

using namespace std;

string posCodes[17]{
        "ST",
        "CF",
        "CAM",
        "CM",
        "CDM",
        "GK",
        "CB",
        "RF",
        "RW",
        "RM",
        "RWB",
        "RB",
        "LF",
        "LW",
        "LM",
        "LWB",
        "LB"
};

float ratings[N];
int count[N];
long positions[N]; // bitmask 17 positions

string names[N];

Node *trie_Names = nullptr;

hashoff<int> usersRatings[N];

struct tag {
    string tag_text;
    hashoff<int> players;
};

hashoff<tag> tags[N];

void printPositions(long posCode) {
    string binary = bitset<17>(posCode).to_string();
    int qtde{0};

    for (int i = 0; i < 17; ++i) {
        if (binary[16 - i] == '1') {
            cout << posCodes[i] << "  ";
            qtde++;
        }
    }

    if (qtde == 1)
        cout << "      \t";
    else if (qtde == 2)
        cout << "   \t";
    else if (qtde == 3)
        cout << "\t";
}

void searchByName(Node *root, const string &name) {
    vector<pair<string, int>> namesPre;
    findNames(root, name.c_str(), namesPre);
    cout << "FIFA_ID\t\t" << "NAME" << string(46, ' ') << "POSITIONS\t\t";
    cout << "RATING\t\t" << "COUNT";
    for (const auto &i:namesPre) {
        cout << endl << i.second << "\t\t" << i.first;
        cout << string(50 - i.first.size(), ' ');
        printPositions(positions[i.second]);
        printf("%.5f\t\t", ratings[i.second] / (float) count[i.second]);
        cout << count[i.second];
    }
    cout << "\n";
}

int main() {
    // initialize hashes
    for (auto &usersRating : usersRatings) {
        usersRating = hashoff<int>(10);
    }
    loadPlayers(&trie_Names, positions, names);
    loadRatings(ratings, count, usersRatings);

//    const char *name = "Bernardo";
//    vector<pair<string, int>> namesPre;
//    findNames(trie_Names, name, namesPre);

//    for (const auto& i:namesPre) {
//        cout << i.first << "  " << i.second << endl;
//    }
//    cout << positions[158023] << endl;

//    cout << (aux >> 0);
//    cout << positions[158023] << endl;
//    cout << positions[2] << endl;
//    cout << positions[4] << endl;
//    printPositions(positions[158023]); cout << endl;
    searchByName(trie_Names, "Rafael");

    return 0;
}

