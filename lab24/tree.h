#ifndef __TREE_H_
#define __TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum type {
    OPERATOR,
    NUMBER,
    VARIABLE,
    BRACKET
}Type;

typedef struct node {
    Type type;
    union {
        int value_int;
        char variable;
        bool is_left_bracket;
        char operation;
    } data;
    int rang;
    struct node* l;
    struct node* r;
}Node;

typedef struct queue{
    Node* front;
    Node* rear;
} queue;

typedef struct stack{
    Node* head;
}stack;

typedef struct tree{
    Node* root;
}tree;

stack* new_stack();
queue* new_queue();
tree* new_tree();
Node* create_node(Type type, int rang);
void push_stack(stack* n, Node* a);
void push_queue(queue* q, Node* a);
Node* pop_stack(stack* n);
Node* pop_queue(queue* q);
void reverse_queue(queue* q);
void print_queue(queue* q);
void from_st_to_q(stack* st, queue* q, Node* n);
Node* add_to_tree(Node* n, queue* q);
tree* create_tree(queue* q);
void print_tree(Node* root, int n);
void remove_zeroes(Node* node);
void print_inf(Node* n);
void print_tree_new(tree* t);
void free_node(Node* n);
void free_tree(tree* t);
#endif
