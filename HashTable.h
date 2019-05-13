#pragma once

//hash table
struct hash_table_t {
  int capacity;
  struct *page *elem;
};

//creation hash table
struct hash_table_t create_hash_table(int capacity);

//find elem in table
struct *page find_elem(int index);

//add elem in table
struct *page add_elem(struct *page elem);

//pop elem from table
void pop_elem(struct *page elem);

//destroy table
void destroy_table(struct *hash_table_t hash_table);
