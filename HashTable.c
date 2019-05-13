#include "HashTable.h"

struct hash_table_t *create_hash_table(int capacity)
{
  if(capacity == 0)
    return NULL;
  struct hash_table_t *res = (struct hash_table_t *) calloc(capacity, sizeof(struct node_t));
  return res;
}

int find_hash(int index)
{
  return index % HASH_MAX_SIZE;
}

struct node_t *add_elem(struct node_t *elem, struct hash_table_t *table)
{
  if((elem == NULL) || (table == NULL))
    return NULL;
  int elem_hash = find_hash(elem->data.index);
  table->elems[elem_hash] = elem;
  return elem;
}

struct node_t *find_elem();
