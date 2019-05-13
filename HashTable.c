#include "HashTable.h"

struct hash_table_t *create_hash_table(int capacity)
{
  if(capacity == 0)
    return NULL;
  struct hash_table_t *res = (hash_table_t *) calloc(capacity, sizeof(struct node_t));
  return res;
}
