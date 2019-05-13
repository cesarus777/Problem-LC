#pragma once

#include "DDLst.h"
#include "HashTable.h"

struct cache_t {
  struct ddlst list;
  struct hash_table_t table;
};

//create cache
struct cache_t create_cache(struct ddlist );

//find elem in cache
struct node_t *find_cache(int index, struct cache_t *cache);

//add elem
struct node_t *push_elem(struct page *p, struct cache_t *cache);
