#ifndef CPD_TRAB_FINAL_DEFINITIONS_H
#define CPD_TRAB_FINAL_DEFINITIONS_H

#include "hashoff.h"
#include "trie.h"

#define N 300000 // max player ID
#define POS_N 17  // max number of positions

void loadPlayers(Node **trie_Names, hashoff<int> positions[POS_N], string names[N]);

void loadRatings(float ratings[N], int count[N], hashRating &usersRatings);

void loadTags(hashtag &tags);

#endif //CPD_TRAB_FINAL_DEFINITIONS_H