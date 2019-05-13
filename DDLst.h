#pragma once
#include <stdlib.h>


enum {SYMBOLS_PER_PAGE = 60};

struct page{
	int index;
	char data[SYMBOLS_PER_PAGE];
};

struct ddlst{
	struct node_t* top;
	struct node_t* last;
	int size;
};


struct node_t{
	struct node_t* next;
	struct node_t* prev;
	struct page    data; 
};

struct ddlst* create_ddlst();

void delete_last(struct ddlst* list);

struct node_t* getTop(struct ddlst* list);

int get_size(struct ddlst* list);

void push(struct ddlst* list, struct page data);

void move_to_top(struct ddlst* list, struct node_t* node);

void clear_ddlst(struct ddlst* list);