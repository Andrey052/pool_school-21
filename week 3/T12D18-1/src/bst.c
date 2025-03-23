#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

node *create(node *root, int key) {
    node *tmp = malloc(sizeof(node));
    tmp->key = key;
    tmp->parent = NULL;
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}

node *bstree_create_node(node *root, int key) {
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp->key = key;
    while (root2 != NULL) {
        root3 = root2;
        if (key < root2->key)
            root2 = root2->left;
        else
            root2 = root2->right;
    }
    tmp->parent = root3;
    tmp->left = NULL;
    tmp->right = NULL;
    if (key < root3->key)
        root3->left = tmp;
    else
        root3->right = tmp;
    return root;
}

void bstree_insert(node **root, int key, int (*cmpf)(int, int)) {
    if (*root == NULL) {
        *root = malloc(sizeof(node));
        (*root)->key = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->parent = NULL;
    } else {
        int comparison = cmpf(key, (*root)->key);
        if (comparison < 0) {
            bstree_insert(&((*root)->left), key, cmpf);
        } else if (comparison > 0) {
            bstree_insert(&((*root)->right), key, cmpf);
        }
    }
}

int compare_ints(int a, int b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

void bstree_apply_infix(node *root, void (*applyf) (int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->key);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(node *root, void (*applyf) (int)) {
    if (root != NULL) {
        applyf(root->key);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(node *root, void (*applyf) (int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->key);
    }
}

void print_key(int key) {
    printf("%d\n", key);
}