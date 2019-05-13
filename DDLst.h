#pragma once
#include <stdlib.h>


enum {SYMBOLS_PER_PAGE = 60};

struct page{
	int index;
	char data[SYMBOLS_PER_PAGE];
};


struct node_t{
	struct node_t* next;
	struct node_t* prev;
	struct page    data; 
};

struct node_t* insert_after(struct node_t* prev, struct page);

void delete_node(struct node_t* node);

void move_to_top(struct node_t* node);

