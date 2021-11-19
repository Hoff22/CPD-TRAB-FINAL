#include <string>
#include "trie.h"

using namespace std;

#define MAX 50

struct Node *newNode(char data, int playerID) {
    auto *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->playerID = playerID;
    temp->isEndOfString = false;
    temp->left = temp->eq = temp->right = nullptr;
    return temp;
}

void insert(struct Node **root, char *word, int playerID) {
    if (!(*root))
        *root = newNode(*word, playerID);

    if ((*word) < (*root)->data)
        insert(&((*root)->left), word, playerID);

    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word, playerID);

    else {
        if (*(word + 1))
            insert(&((*root)->eq), word + 1, playerID);
        else
            (*root)->isEndOfString = true;
    }
}

void traverseTSTUtil(struct Node *root, char *buffer, int depth) {
    if (root) {
        traverseTSTUtil(root->left, buffer, depth);

        buffer[depth] = root->data;
        if (root->isEndOfString) {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        traverseTSTUtil(root->eq, buffer, depth + 1);
        traverseTSTUtil(root->right, buffer, depth);
    }
}

void traverseTST(struct Node *root) {
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

int searchTST(struct Node *root, char *word) {
    if (!root)
        return -1;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    if (*word > (root)->data)
        return searchTST(root->right, word);

    if (*(word + 1) == '\0')
        return root->playerID;

    return searchTST(root->eq, word + 1);

}
