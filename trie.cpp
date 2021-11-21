#include <string>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include "trie.h"
#include <iostream>

using namespace std;

#define MAX 50

Node *newNode(char data) {
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->playerID = -1;
    temp->left = temp->mid = temp->right = nullptr;
    return temp;
}

void insert(Node **root, const char *word, int playerID) {
    if (!(*root))
        *root = newNode(*word);

    if ((*word) < (*root)->data)
        insert(&((*root)->left), word, playerID);

    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word, playerID);

    else {
        if (*(word + 1))
            insert(&((*root)->mid), word + 1, playerID);
        else
            (*root)->playerID = playerID;
    }
}

void auxShowTrie(Node *root, char *buffer, int depth, vector<pair<string, int>> &namesPre, const char *word) {
    if (root) {
        auxShowTrie(root->left, buffer, depth, namesPre, word);

        buffer[depth] = root->data;
        if (root->playerID != -1) {
            buffer[depth + 1] = '\0';
            string tmp = buffer;
            namesPre.emplace_back(make_pair(tmp, root->playerID));
        }

        auxShowTrie(root->mid, buffer, depth + 1, namesPre, word);
        auxShowTrie(root->right, buffer, depth, namesPre, word);
    }
}

void showTrie(Node *root, vector<pair<string, int>> &namesPre, const char *word, int size) {
    char buffer[MAX];
    strcpy(buffer, word);
    auxShowTrie(root, buffer, size, namesPre, word);
}

void findNames(Node *root, const char *name, vector<pair<string, int>> &namesPre, int size) {
    if (root) {
        if (name[0] == '\0')
            showTrie(root, namesPre, name - size, size);
        else if (root->data == name[0])
            if (name[1] == '\0')
                showTrie(root->mid, namesPre, name - size, size + 1);
            else
                findNames(root->mid, name + 1, namesPre, size + 1);
        else if (root->data > name[0])
            findNames(root->left, name, namesPre, size);
        else if (root->data < name[0])
            findNames(root->right, name, namesPre, size);
    }
}

int searchTST(Node *root, char *word) {
    if (!root)
        return -1;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    if (*word > (root)->data)
        return searchTST(root->right, word);

    if (*(word + 1) == '\0')
        return root->playerID;

    return searchTST(root->mid, word + 1);
}

// A recursive function to traverse Ternary Search Tree
void traverseTSTUtil(struct Node *root, char *buffer, int depth) {
    if (root) {
        // First traverse the left subtree
        traverseTSTUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->data;
        if (root->playerID != -1) {
            buffer[depth + 1] = '\0';
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseTSTUtil(root->mid, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void traverseTST(struct Node *root) {
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}
