//
// Created by goldenf2 on 11/19/21.
//

#ifndef CPD_TRAB_FINAL_TRIE_H
#define CPD_TRAB_FINAL_TRIE_H

#include <vector>
#include <string>

using namespace std;
// A node of ternary search tree
struct Node {
    char data;
    int playerID;
    struct Node *left, *mid, *right;
};

void insert(Node **root, const char *word, int playerID);

void findNames(Node *root, const char *name, vector<pair<string, int>> &namesPre, int size = 0);


#endif //CPD_TRAB_FINAL_TRIE_H
