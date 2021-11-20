//
// Created by goldenf2 on 11/19/21.
//

#ifndef CPD_TRAB_FINAL_TRIE_H
#define CPD_TRAB_FINAL_TRIE_H

using namespace std;
// A node of ternary search tree
struct Node {
    char data;
    int playerID;
    struct Node *left, *mid, *right;
};

Node *newNode(char data);
void insert(Node **root, char *word, int playerID) ;
void findNames(Node *root, char *name, vector<pair<string, int>> &namesPre, int size=0);
int searchTST(Node *root, char *word);
void traverseTST(struct Node *root);

#endif //CPD_TRAB_FINAL_TRIE_H
