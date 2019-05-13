#pragma once

//hash table
struct hash_table_t {
  int capacity;
  struct node_t **elem;
};

//creation hash table
struct hash_table_t create_hash_table(int capacity);

//find elem in table
struct node_t *find_elem(int index);

//add elem in table
struct node_t *add_elem(struct node_t *elem);

//pop elem from table
void pop_elem(struct node_t *elem);

//destroy table
void destroy_table(struct hash_table_t *hash_table);
