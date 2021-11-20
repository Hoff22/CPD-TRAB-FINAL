#include <cstring>
#include "definitions.h"
#include "hashoff.cpp"
#include "trie.h"

using namespace std;

float ratings[N];
int count[N];
int positions[N]; // bitmask 21 positions

string names[N];

struct tag {
    string str;
    hashoff<int> players = hashoff<int>(30000);
};
int size(char *kk){
    return (sizeof kk);
}
int main() {

    hashoff<string> superset(100);

    superset.insert("abobora");

    cout << "o set tem abgfhj?" << superset.count("abgfhj") << endl;
    cout << "o set tem abobora?" << superset.count("abobora") << endl;

    Node *root = nullptr;
    char ex1[] = "cat";
    char ex2[] = "cats";
    char ex3[] = "up";
    char ex4[] = "bug";
    char ex5[] = "buy";

    insert(&root, ex1, 1);
    insert(&root, ex2, 2);
    insert(&root, ex3, 3);
    insert(&root, ex4, 4);
    insert(&root, ex5, 5);

//    showTrie(root);

//    cout << searchTST(root, ex2) << endl;
//    cout << searchTST(root, ex5) << endl;
//    cout << searchTST(root, ex1) << endl;

//    cout << root->playerID << endl;

    static vector<pair<string, int>> namesPre;
//
    char kk[] = "b\0";
    findNames(root, kk, namesPre);
//
    for (const auto& i: namesPre){
        cout << i.first << " - " << i.second << endl;
    }
    namesPre.clear();
    strcpy(kk, "cat");
    findNames(root, kk, namesPre);
    //
    for (const auto& i: namesPre){
        cout << i.first << " - " << i.second << endl;
    }


    cout << "\n\n";
    traverseTST(root);




    return 0;
}

