#include <cstring>
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
int positions[N]; // bitmask 21 positions

string names[N];

Node* trie_Names = nullptr;

hashoff<int> usersRatings[N];

struct tag{
    string tag_text;
    hashoff<int> players;
}

hashoff<tag> tags[N];

int main() {

    // initialize hashes
    for(int i = 0; i < N; i++){
        usersRatings[i] = hashoff<int>(10);
    }

    loadPlayers(&trie_Names, positions, names);

    loadRatings(ratings, count, usersRatings);



    return 0;
}

