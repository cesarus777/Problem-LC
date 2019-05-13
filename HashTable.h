#pragma once
#include "DDLst.h"

//hash table
struct hash_table_t {
  int capacity;
  struct node_t **elems;
};

enum { HASH_MAX_SIZE = 100 };

//find hash
int find_hash(int index);

//creation hash table
struct hash_table_t create_hash_table(int capacity);

//find elem in table
struct node_t *find_elem(int index, struct hash_table_t *table);

//add elem in table
struct node_t *add_elem(struct node_t *elem, struct hash_table_t *table);

//pop elem from table
void pop_elem(struct node_t *elem, struct hash_table_t *table);

//destroy table
void destroy_hash_table(struct hash_table_t *table);
