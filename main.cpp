#include <iomanip>
#include <bitset>
#include <algorithm>
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
int ratingCount[N];
hashoff<int> positions[POS_N]; // bitmask 17 positions

string names[N];

Node *trieNames = nullptr;

hashoff<int> usersRatings[N];

hashtag tags(200000);

// Funcao para armazenar os dados de um arquivo em um vector
vector<string> splitLine(const string &str, const string &delimiter = " ") {
    vector<string> vector;
    size_t start = 0;
    size_t end = str.find(delimiter);
    string temp;
    while (end != -1) {
        temp = str.substr(start, end - start);
        if (temp != " " && !temp.empty()) vector.emplace_back(temp);

        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    temp = str.substr(start, end - start);
    if (temp != " " && !temp.empty()) vector.emplace_back(temp);
    return vector;
}

// last element is taken as pivot
int Partition(vector<int> &v, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
        if (ratings[v[i]] / (float) ratingCount[v[i]] > ratings[v[pivot]] / (float) ratingCount[v[pivot]]) {
            swap(v[i], v[j]);
            ++j;
        }
    swap(v[j], v[pivot]);
    return j;
}

void Quicksort(vector<int> &v, int start, int end) {
    if (start < end) {
        int p = Partition(v, start, end);
        Quicksort(v, start, p - 1);
        Quicksort(v, p + 1, end);
    }
}

void printPositions(int id) {
    int qtde = 0;

    for (int i = 0; i < POS_N; i++) {
        if (positions[i].count(id)) {
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

void printTabela(const vector<int> &ids) {
    cout << "FIFA_ID\t\t" << "NAME" << string(46, ' ') << "POSITIONS\t";
    cout << "RATING\t\t" << "COUNT";
    for (auto id : ids) {
        cout << endl << id << "\t\t" << names[id];
        cout << string(50 - names[id].size(), ' ');
        printPositions(id);
        cout << setprecision(5) << ratings[id] / (float) ratingCount[id] << "\t\t";
        cout << ratingCount[id];
    }
    cout << "\n";
}

void searchByName(Node *root, const string &name) {
    vector<pair<string, int>> namesPre;
    findNames(root, name.c_str(), namesPre);

    vector<int> ids;
    ids.reserve(namesPre.size());
    for (const auto &i : namesPre) {
        ids.push_back(i.second);
    }

    printTabela(ids);
}

vector<int> intersection(vector<int> v1, vector<int> v2) {
    vector<int> v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    return v3;
}

void searchByTag(const string &t) {
    vector<string> requestedTags = splitLine(t, "'");

    vector<int> aux;
    if (tags.count(requestedTags[0]))
        aux = tags.getData(requestedTags[0]);

    for (int i = 1; i < requestedTags.size(); i++)
        if (tags.count(requestedTags[i]))
            aux = intersection(aux, tags.getData(requestedTags[i]));

    printTabela(aux);
}

void mainLoop() {
    string type, info;
    cout << "comando: " << endl;
    getline(cin, type, ' ');
    getline(cin, info);

    if (type == "player") {
        searchByName(trieNames, info);
    } else if (type == "user") {

    } else if (type.substr(0, 3) == "top") {
        int num = stoi(type.substr(3, 5));

    } else if (type == "tags") {
        searchByTag(info);
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
    loadPlayers(&trieNames, positions, names);
    loadRatings(ratings, ratingCount, usersRatings);
//    loadTags(tags);
//    mainLoop();


    return 0;
}

