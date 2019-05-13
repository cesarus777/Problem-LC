#include "stdlib.h"

#include "HashTable.h"

struct hash_table_t create_hash_table(int capacity)
{
  struct hash_table_t res = { 0, NULL };
  if(capacity == 0)
    return res;
  res.capacity = capacity;
  res.elems = (struct node_t **) calloc(capacity, sizeof(struct node_t));
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

struct node_t *find_elem(struct node_t *elem, struct hash_table_t *table)
{
  if((elem == NULL) || (table == NULL))
    return NULL;
  int elem_hash = find_hash(elem->data.index);
  if(table->elems[elem_hash] == elem)
    return table->elems[elem_hash];
  return NULL;
}

void pop_elem(struct node_t *elem, struct hash_table_t *table)
{
  if((elem == NULL) || (table == NULL))
    return;
  int elem_hash = find_hash(elem->data.index);
  if(table->elems[elem_hash] == elem)
    table->elems[elem_hash] = NULL;
}

void destroy_hash_table(struct hash_table_t *table)
{
  table->capacity = 0;
  free(table->elems);
}
