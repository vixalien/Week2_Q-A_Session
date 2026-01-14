// NETWORK PROTOCOL v1.0 - ALL NODES MUST COMPLY
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <time.h>
typedef struct Block {
    int index;
    time_t timestamp;
    char data[256];
    char previous_hash[65];
    char hash[65];
    int nonce;
} Block;
// Function Contracts - Implement these
void hash_block(Block *block);
Block* create_genesis_block();
int add_block(Block *chain[], int *size, const char *data);
int is_chain_valid(Block *chain[], int size);
void mine_block(Block *block, int difficulty);
#endif



