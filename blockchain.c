#include "blockchain.h"
#include <stdlib.h>
#include <string.h>

Block *create_block(const char *data, int *size) {
  Block *block = malloc(sizeof(Block));
  if (!block) {
    return NULL;
  }
  strncpy(block->data, data, strlen(data));
  block->data[255] = '\0';
  block->index = *size;
  block->timestamp = time(NULL);



  return block;
}

int add_block(Block *chain[], int *size, const char *data) {
  Block *new_block = (Block*)malloc(sizeof(Block));
  if (!new_block) {
      return 0;
  }

  new_block->index = *size;
  new_block->timestamp = time(NULL);
  strncpy(new_block->data, data, 255);
  new_block->data[255] = '\0';

  // Get previous block's hash
  if (*size > 0) {
      strcpy(new_block->previous_hash, chain[*size - 1]->hash);
  } else {
      strcpy(new_block->previous_hash, "0");
  }

  // Get previous block's hash
  if (*size > 0) {
      strcpy(new_block->previous_hash, chain[*size - 1]->hash);
  } else {
      strcpy(new_block->previous_hash, "0");
  }

  mine_block(new_block, 4);

  chain[*size] = new_block;
  (*size)++;

  return 1;
}

void mine_block(Block *block, int difficulty) {
  char target[65] = {0};

  for (int i = 0; i < difficulty; i++) {
    target[i] = '0';
  }

  block->nonce = 0;
  hash_block(block);

  while (strncmp(block->hash, target, difficulty)) {
    block->nonce++;
    hash_block(block);
  }
}
