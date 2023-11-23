#ifndef __TABLE_H__
#define __TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define STRSIZE 100

typedef struct Node {
    int key;
    char string[STRSIZE];
} Node;

typedef struct List {
    Node* value;
    int size;
} List;

List* create_list ();
void print_table(List* list);
void swap_nodes(List* list, int a, int b);
int is_sorted(List* list);
void reverse_table(List* list);
void scramble_table(List* list);
void sort_table(List* list);
int bin_search(List* list, Node key);
void remove_table(List* list);

#endif
