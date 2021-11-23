#include <fstream>
#include "definitions.h"

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

vector<int> parsePositions(string list) {

    vector<int> mask;

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

            if (cur_pos == "ST")
                mask.push_back(0);
            else if (cur_pos == "CF")
                mask.push_back(1);
            else if (cur_pos == "CAM")
                mask.push_back(2);
            else if (cur_pos == "CM")
                mask.push_back(3);
            else if (cur_pos == "CDM")
                mask.push_back(4);
            else if (cur_pos == "GK")
                mask.push_back(5);
            else if (cur_pos == "CB")
                mask.push_back(6);
            else if (cur_pos == "RF")
                mask.push_back(7);
            else if (cur_pos == "RW")
                mask.push_back(8);
            else if (cur_pos == "RM")
                mask.push_back(9);
            else if (cur_pos == "RWB")
                mask.push_back(10);
            else if (cur_pos == "RB")
                mask.push_back(11);
            else if (cur_pos == "LF")
                mask.push_back(12);
            else if (cur_pos == "LW")
                mask.push_back(13);
            else if (cur_pos == "LM")
                mask.push_back(14);
            else if (cur_pos == "LWB")
                mask.push_back(15);
            else if (cur_pos == "LB")
                mask.push_back(16);

            j = i + 1;
        }
    }
    return mask;
}

void loadPlayers(Node **trie_Names, hashoff<int> positions[POS_N], string names[N]) {
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
        for (int pos : parsePositions(cur_pos)) {
            positions[pos].insert(cur_id);
        }
        names[cur_id] = cur_name;
        insert(trie_Names, cur_name.c_str(), cur_id);
    }

    file.close();
}

void loadRatings(float ratings[N], int count[N], hashRating &usersRatings) {
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
        file >> virgula;

        // read player
        file >> player_id;

        // wasted comma
        file >> virgula;

        // read user's raiting for said player
        file >> user_rating;

        ratings[player_id] += user_rating;
        count[player_id]++;

        usersRatings.insert(user_id, player_id, user_rating);
    }
    file.close();
}

void loadTags(hashtag &tags) {
    ifstream file("tags.csv");

    string aux;
    getline(file, aux);
    while (file) {
        int player_id;
        char virgula;
        string cur_tag;

        // read user
        file >> player_id; // never used, trhow away

        // wasted comma
        file >> virgula;

        // read player
        file >> player_id;

        // wasted comma
        file >> virgula;

        // read name
        getline(file, cur_tag);

        if (tags.countID({cur_tag, player_id})) {
            continue;
        }
        tags.insert({cur_tag, player_id});
    }

    file.close();
}