#include "tree.h"

#include <stdio.h>

//Функция создания дерева
Tree* create_tree(int value) {
    Tree* new_Tree = (Tree*)malloc(sizeof(Tree));
    new_Tree->value = value;
    new_Tree->left = NULL;
    new_Tree->right = NULL;
    return new_Tree;
}

//Функция добавления новой вершины
Tree* insert_node(Tree* root, int value) {
	if(root == NULL) 
		return create_tree(value);
    	if(value < root->value)
    		root->left = insert_node(root->left, value);
    	else if(value > root->value)
    		root->right = insert_node(root->right, value);
    return root;
}

//Функция поиска минимума
Tree* find_minimum(Tree* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

//Функция удаления вершины
Tree* remove_node(Tree* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = remove_node(root->left, value);
    } else if (value > root->value) {
        root->right = remove_node(root->right, value);
    } else {
        if (root->left == NULL) {
            Tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Tree* temp = root->left;
            free(root);
            return temp;
        }
        Tree* temp = find_minimum(root->right);
        root->value = temp->value;
        root->right = remove_node(root->right, temp->value);
    }
    return root;
}

//Функция вывода дерева
void print_tree(Tree* root, int n) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, n + 1);
    for (int i = 0; i < n; i++) printf("\t");
    printf("%d\n", root->value);
    print_tree(root->left, n + 1);
}

//Проверка, находится ли значение листа в диапазоне
int is_leaf_in_range(Tree* root, int min, int max) 
{ 
    if (root == NULL) 
        return 1; 

    if (root->left == NULL && root->right == NULL) 
        return (root->value >= min && root->value <= max);

    return is_leaf_in_range(root->left, min, max) && is_leaf_in_range(root->right, min, max); 
} 

//Функция удаления дерева
void free_tree(Tree* root) {
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
