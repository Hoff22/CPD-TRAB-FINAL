#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include "trie.h"

using namespace std;

#define MAX 50

Node *newNode(char data) {
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->left = temp->mid = temp->right = nullptr;
    temp->playerID = -1;
    temp->data = data;
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

void auxSaveName(Node *root, char *buffer, int depth, vector<pair<string, int>> &namesPre, const char *word) {
    if (root) {
        auxSaveName(root->left, buffer, depth, namesPre, word);

        buffer[depth] = root->data;
        if (root->playerID != -1) {
            buffer[depth + 1] = '\0';
            string tmp = buffer;
            namesPre.emplace_back(make_pair(tmp, root->playerID));
        }

        auxSaveName(root->mid, buffer, depth + 1, namesPre, word);
        auxSaveName(root->right, buffer, depth, namesPre, word);
    }
}

void saveName(Node *root, vector<pair<string, int>> &namesPre, const char *word, int size) {
    char buffer[MAX];
    strcpy(buffer, word);
    auxSaveName(root, buffer, size, namesPre, word);
}

void findNames(Node *root, const char *name, vector<pair<string, int>> &namesPre, int size) {
    if (root) {
        if (name[0] == '\0')
            saveName(root, namesPre, name - size, size);
        else if (root->data == name[0])
            if (name[1] == '\0')
                saveName(root->mid, namesPre, name - size, size + 1);
            else
                findNames(root->mid, name + 1, namesPre, size + 1);
        else if (root->data > name[0])
            findNames(root->left, name, namesPre, size);
        else if (root->data < name[0])
            findNames(root->right, name, namesPre, size);
    }
}
