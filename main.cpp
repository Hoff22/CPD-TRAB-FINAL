#include <iomanip>
#include <bitset>
#include "hashoff.h"
#include "definitions.h"
#include "trie.h"

#define N 300000 // max player ID
#define POS_N 17  // max number of positions

using namespace std;

string posCodes[POS_N]{
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
hashoff<int> positions[POS_N]; // bitmask 17 positions

string names[N];

Node *trie_Names = nullptr;

hashoff<int> usersRatings[N];

hashtag tags(200000);

void printPositions(int id) {
    
    int qtde = 0;

    for(int i = 0; i < POS_N; i++){
        if(positions[i].count(id)){
            cout << posCodes[i] << " ";
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

void printTabela(vector<int> ids){
    cout << "FIFA_ID\t\t" << "NAME" << string(46, ' ') << "POSITIONS\t";
    cout << "RATING\t\t" << "COUNT";
    for (auto id : ids) {
        cout << endl << id << "\t\t" << names[id];
        cout << string(50 - names[id].size(), ' ');
        printPositions(id);
        cout << setprecision(5) << ratings[id] / (float)count[id] << "\t\t";
        cout << count[id];
    }
    cout << "\n";
}

void searchByName(Node *root, const string &name) {
    vector<pair<string, int>> namesPre;
    findNames(root, name.c_str(), namesPre);
    
    vector<int> ids;
    for(auto i : namesPre){
        ids.push_back(i.second);
    }

    printTabela(ids);
}

void searchByTag(string t){
    if(tags.count(t)){
        printTabela(tags.getData(t));
    }
}

int main() {
    // initialize hashes
    for (auto &usersRating : usersRatings) {
        usersRating = hashoff<int>(10);
    }
    for (auto &position : positions) {
        position = hashoff<int>(3000);
    }
    loadPlayers(&trie_Names, positions, names);
    loadRatings(ratings, count, usersRatings);
    loadTags(tags);

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
    // searchByName(trie_Names, "Lionel");
    searchByTag("Clinical Finisher");

    return 0;
}

