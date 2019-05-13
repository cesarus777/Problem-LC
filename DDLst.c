#include "DDLst.h"





void clear_ddlst(struct ddlst* list){
	if(!list)
		return;
	
	struct node_t* tmp = list->top;
	
	while(tmp){
		struct node_t* tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	list->top = NULL;
	list->last = NULL;
	list->size = 0;
}

void move_to_top(struct ddlst* list, struct node_t* node){
	if(!list || !node)
		return;
	
	if(node->next)
		node->next->prev = node->prev;
	if(node->prev)
		node->prev->next = node->next;
	node->next = list->top;
	node->prev = NULL;
	list->top = node;
}


struct ddlst* create_ddlst(){
	struct ddlst* ret = (struct ddlst*)malloc(sizeof(struct ddlst));
	ret->size = 0;
	ret->top = NULL;
	ret->last = NULL;
	return ret;
}

void delete_last(struct ddlst* list){
	if(!list || !list->last)
		return;
	
	if(list->last->prev)
		list->last->prev->next = NULL;
	
	struct node_t* newlast = list->last->prev;
	free(list->last);
	list->last = newlast;
	list->size--;
}

struct node_t* getTop(struct ddlst* list){
	return (list) ? list->top : NULL;
}

int get_size(struct ddlst* list){
	return (list) ? list->size : 0;	
}

void push(struct ddlst* list, struct page data){
	if(!list)
		return;
	struct node_t* newnode = (struct node_t*)malloc(sizeof(struct node_t));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = list->top;
	list->top = newnode;
	list->size++;
}

