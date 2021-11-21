#include <fstream>
#include <string>
#include "hashoff.h"
#include "trie.h"

#define N 300000 // max player ID

using namespace std;

// 0  : ST
// 1  : CF
// 2  : CAM
// 3  : CM
// 4  : CDM
// 5  : GK
// 6  : CB
// 7  : RF
// 8  : RW
// 9  : RM
// 10 : RWB
// 11 : RB
// 12 : LF
// 13 : LW
// 14 : LM
// 15 : LWB
// 16 : LB

int parsePositions(string list) {

    int mask = 0;

    if (list[list.size() - 1] == '"') list[list.size() - 1] = ',';
    else list += ',';

    int j = 0;
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == '"' or list[i] == ' ') {
            j++;
            continue;
        }

        if (list[i] == ',') {
            string cur_pos = list.substr(j, (i - j));

            if (cur_pos == "ST") {
                //
                mask |= (1 << 0);
            } else if (cur_pos == "CF") {
                //
                mask |= (1 << 1);
            } else if (cur_pos == "CAM") {
                //
                mask |= (1 << 2);
            } else if (cur_pos == "CM") {
                //
                mask |= (1 << 3);
            } else if (cur_pos == "CDM") {
                //
                mask |= (1 << 4);
            } else if (cur_pos == "GK") {
                //
                mask |= (1 << 5);
            } else if (cur_pos == "CB") {
                //
                mask |= (1 << 6);
            } else if (cur_pos == "RF") {
                //
                mask |= (1 << 7);
            } else if (cur_pos == "RW") {
                //
                mask |= (1 << 8);
            } else if (cur_pos == "RM") {
                //
                mask |= (1 << 9);
            } else if (cur_pos == "RWB") {
                //
                mask |= (1 << 10);
            } else if (cur_pos == "RB") {
                //
                mask |= (1 << 11);
            } else if (cur_pos == "LF") {
                //
                mask |= (1 << 12);
            } else if (cur_pos == "LW") {
                //
                mask |= (1 << 13);
            } else if (cur_pos == "LM") {
                //
                mask |= (1 << 14);
            } else if (cur_pos == "LWB") {
                //
                mask |= (1 << 15);
            } else if (cur_pos == "LB") {
                //
                mask |= (1 << 16);
            }

            j = i + 1;
        }
    }

    return mask;
}

void loadPlayers(Node **trie_Names, int positions[N], string names[N]) {
    ifstream file("players.csv");

    string aux;
    file >> aux;

    while (file) {
        // read id
        int cur_id;
        file >> cur_id;

        // wasted comma
        char virgula;
        file >> virgula;

        // read name
        string cur_name;
        getline(file, cur_name, ',');

        // read positions
        string cur_pos;
        getline(file, cur_pos);

        // initialize coisas
        positions[cur_id] = parsePositions(cur_pos);
        names[cur_id] = cur_name;
        insert(trie_Names, cur_name.c_str(), cur_id);
    }

    file.close();
}

void loadRatings(float ratings[N], int count[N], hashoff<int> usersRatings[N]) {
    ifstream file("rating.csv");

    string aux;
    getline(file, aux);
    while (file) {
        int user_id;
        int player_id;
        float user_rating;
        char virgula;

        // read user
        file >> user_id;

        // wasted comma
        virgula;
        file >> virgula;

        // read player
        file >> player_id;

        // wasted comma
        virgula;
        file >> virgula;

        // read user's raiting for said player
        file >> user_rating;

        //
        ratings[player_id] += user_rating;
        count[player_id]++;

        usersRatings[user_id].insert(player_id);
    }


    file.close();
}

void loadTags(hashoff<string> tags[N]) {
    ifstream file("rating.csv");

    string aux;
    getline(file, aux);
    while (file) {
        int user_id;
        int player_id;
        char virgula;
        string cur_name;

        // read user
        file >> user_id;

        // wasted comma
        virgula;
        file >> virgula;

        // read player
        file >> player_id;

        // wasted comma
        virgula;
        file >> virgula;

        // read name
        getline(file, cur_name);

//        tag aux{};
//        tags[user_id].insert()
    }


    file.close();
}