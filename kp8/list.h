#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef struct node {
    uint64_t data;
    struct node* next;
} Node;

typedef struct list {
	Node* head;
} List;

List* create_list();
void push_node(List* list, uint64_t data);
void pop_node(List* list);
void print_list(List* list);
int size_of_list(List* list);
void remove_range(List* list, uint64_t lower, uint64_t upper);
void destroy_list(List* list);

#endif //__LIST_H__
