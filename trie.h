//
// Created by goldenf2 on 11/19/21.
//

#ifndef CPD_TRAB_FINAL_TRIE_H
#define CPD_TRAB_FINAL_TRIE_H

// A node of ternary search tree
struct Node {
    char data;
    int playerID;
    bool isEndOfString;
    struct Node *left, *eq, *right;
};

struct Node *newNode(char data, int playerID);
void insert(struct Node **root, char *word, int playerID) ;
void traverseTSTUtil(struct Node *root, char *buffer, int depth) ;
void traverseTST(struct Node *root);
int searchTST(struct Node *root, char *word);

#endif //CPD_TRAB_FINAL_TRIE_H
