#ifndef __TREE_H__
#define __TREE_H__
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* create_tree(int value);
Tree* insert_node(Tree* root, int value);
Tree* remove_node(Tree* root, int key);
Tree* find_minimum(Tree* root);
int is_leaf_in_range(Tree* root, int min, int max);
void print_tree(Tree* root, int n);
void free_tree(Tree* root);

#endif // __TREE_H__
