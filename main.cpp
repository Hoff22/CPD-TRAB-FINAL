#include <iomanip>
#include <algorithm>
#include <chrono>
#include "definitions.h"

using namespace std;


string posCodes[POS_N]{"ST", "CF", "CAM", "CM", "CDM", "GK", "CB", "RF", "RW", "RM", "RWB", "RB", "LF", "LW", "LM",
                       "LWB", "LB"};

float ratings[N];
int ratingCount[N];
hashoff<int> positions[POS_N];

string names[N];

Node *trieNames = nullptr;

hashRating usersRatings(20000);

hashtag tags(200000);

vector<string> splitLine(const string &str, const string &delimiter) {
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

bool is_number(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// last element is taken as pivot
int Partition(vector<int> &v, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
        if (ratings[v[i]] / ((float) ratingCount[v[i]] + (float) (ratingCount[v[i]] == 0)) >
            ratings[v[pivot]] / ((float) ratingCount[v[pivot]] + (float) (ratingCount[v[pivot]] == 0))) {
            swap(v[i], v[j]);
            ++j;
        }
    swap(v[j], v[pivot]);
    return j;
}

void sortVector(vector<int> &v, int start, int end) {
    if (start < end) {
        int p = Partition(v, start, end);
        sortVector(v, start, p - 1);
        sortVector(v, p + 1, end);
    }
}

// last element is taken as pivot
int Partition(vector<pair<int, float>> &v, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i)
        if (v[i].second > v[pivot].second) {
            swap(v[i], v[j]);
            ++j;
        }
    swap(v[j], v[pivot]);
    return j;
}

void sortVector(vector<pair<int, float>> &v, int start, int end) {
    if (start < end) {
        int p = Partition(v, start, end);
        sortVector(v, start, p - 1);
        sortVector(v, p + 1, end);
    }
}

void printPositions(int id) {
    int qtde = 0;

    for (int i = 0; i < POS_N; i++)
        if (positions[i].count(id)) {
            cout << posCodes[i] << " ";
            qtde++;
        }

    if (qtde == 1)
        cout << "      \t";
    else if (qtde == 2)
        cout << "   \t";
    else if (qtde == 3)
        cout << "\t";
}

void printTable(const vector<int> &ids) {
    cout << "FIFA_ID\t\t" << "NAME" << string(46, ' ') << "POSITIONS\t";
    cout << "RATING\t\t" << "COUNT";
    for (auto id : ids) {
        cout << endl << id << "\t\t" << names[id];
        cout << string(50 - names[id].size(), ' ');
        printPositions(id);
        if (ratingCount[id] == 0) {
            cout << "noRate" << "\t\t";
        } else {
            cout << setprecision(5) << ratings[id] / (float) ratingCount[id] << "\t\t";
        }
        cout << ratingCount[id];
    }
    cout << "\n";
}

void printUsrTable(vector<pair<int, float>> &data) {
    cout << "FIFA_ID\t\t" << "NAME" << string(46, ' ') << "GLOBAL_RATING\t\t" << "COUNT\t\t" << "RATING";
    sortVector(data, 0, (int) data.size() - 1);
    if (data.size() > 20)
        data.resize(20);
    for (auto player : data) {
        int id = player.first;
        float user_rating = player.second;

        float media = ratings[id] / (float) ratingCount[id];
        cout << endl << id << "\t\t" << names[id];
        cout << string(50 - names[id].size(), ' ');
        if (media == 0) {
            cout << "noRate" << "\t\t";
        } else {
            cout << fixed << setprecision(5) << media << "\t\t";
        }
        cout << ratingCount[id] << "\t\t";
        cout << fixed << setprecision(1) << user_rating;
    }
    cout << "\n";
}

void searchByName(Node *root, const string &name) {
    vector<pair<string, int>> namesPre;
    findNames(root, name.c_str(), namesPre);

    vector<int> ids;
    ids.reserve(namesPre.size());
    for (const auto &i : namesPre)
        ids.push_back(i.second);

    printTable(ids);
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
    if (tags.count(requestedTags[0])) {
        aux = tags.getData(requestedTags[0]);
    } else {
        cout << "Inexistent tag.\n";
        return;
    }

    for (int i = 1; i < requestedTags.size(); i++) {
        if (tags.count(requestedTags[i])) {
            aux = intersection(aux, tags.getData(requestedTags[i]));
        } else {
            cout << "Inexistent tag.\n";
            return;
        }
    }
    printTable(aux);
}

void searchTopPos(int pos, string info) {
    info.erase(remove(info.begin(), info.end(), '\''), info.end());
    vector<int> aux;
    for (int i = 0; i < POS_N; i++)
        if (posCodes[i] == info) {
            aux = positions[i].getData();
            break;
        }

    if (aux.empty()) {
        cout << "No player with this tag.\n";
        return;
    }

    sortVector(aux, 0, (int) aux.size() - 1);
    if (aux.size() > pos)
        aux.resize(pos);
    printTable(aux);
}

void helpDisplay() {
    cout << " -> Available Options:\n";
    cout << " player <name or prefix>\n";
    cout << " user <userID>\n";
    cout << " top<N> '<position>'\n";
    cout << " tags <list of tags>\n";
    cout << " exit <x>\n";
}

void mainLoop() {
    string type, info;
    cout << endl;
    cout << string(10, ' ') << "TRABALHO FINAL - CLASSIFICACAO E PESQUISA DE DADOS\n";
    cout << string(18, ' ') << "SEARCH IN FIFA21 DATASET - PLAYERS\n";
    cout << string(17, ' ') << "ARTHUR BITTENCOURT HOFF -- 00324628\n";
    cout << string(14, ' ') << "LUIS GUILHERME FERNANDES MELO -- 00326620\n\n";

    while (true) {
        cout << ">> ";
        getline(cin, type, ' ');
        getline(cin, info);

        if (type == "player") {
            searchByName(trieNames, info);
        } else if (type == "user") {
            if (!is_number(info)) {
                cout << "Invalid user id.\n";
            } else {
                vector<pair<int, float>> aux = usersRatings.getData(stoi(info));
                printUsrTable(aux);
            }
        } else if (type.substr(0, 3) == "top") {
            searchTopPos(stoi(type.substr(3, 5)), info);
        } else if (type == "tags") {
            searchByTag(info);
        } else if (type == "exit") {
            cout << "Ending Program..." << endl;
            break;
        } else if (type == "help") {
            helpDisplay();
        } else {
            cout << "Invalid command... Try again." << endl;
        }
        cout << endl;
    }
}

int main() {
//initialize hashes
    cout << "Processando dados...\n";
    cout.flush();

    auto start = chrono::high_resolution_clock::now();
    for (auto &position : positions) {
        position = hashoff<int>(3000);
    }

    loadPlayers(&trieNames, positions, names);
    loadRatings(ratings, ratingCount, usersRatings);
    loadTags(tags);
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::seconds>(stop - start);

    cout << "Dados processados em " << duration.count() << " segundos" << endl;

    mainLoop();


    return 0;
}
