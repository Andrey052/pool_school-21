#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

int main() {
    node* root = NULL;
    root = create(root, 17);
#ifdef Q_3
    root = bstree_create_node(root, 18);
    root = bstree_create_node(root, 10);
    printf("\t%d\n", root->key);
    if (root->left == NULL) {
        printf("Узла нет\t%d\n", root->right->key);
    } else if (root->right == NULL) {
        printf("%d\t Узла нет\n", root->left->key);
    } else {
        printf("%d\t\t%d\n", root->left->key, root->right->key);
    }
    free(root->left);
    free(root->right);
    free(root);
#elif Q_4
    bstree_insert(&root, 13, compare_ints);
    bstree_insert(&root, 18, compare_ints);
    bstree_insert(&root, 12, compare_ints);
    bstree_insert(&root, 14, compare_ints);
    printf("\t\t%d\n", root->key);
    // printf("");
    printf("\t%d\t\t%d\n", root->left->key, root->right->key);
    printf("%d\t\t%d", root->left->left->key, root->left->right->key);
    // if (root->left == NULL) {
    //     printf("Узла нет\t%d\n", root->right->key);
    // } else if (root->right == NULL) {
    //     printf("%d\t Узла нет\n", root->left->key);
    // }else{
    //     printf("%d\t\t%d\n",root->left->key, root->right->key);
    // }
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
#else
    bstree_insert(&root, 13, compare_ints);
    bstree_insert(&root, 18, compare_ints);
    bstree_insert(&root, 12, compare_ints);
    bstree_insert(&root, 14, compare_ints);
    printf("bstree_apply_infix\n");//симметричный
    bstree_apply_infix(root, print_key);
    printf("bstree_apply_prefix\n");//прямой обход
    bstree_apply_prefix(root, print_key);
    printf("bstree_apply_postfix\n");//обратнный
    bstree_apply_postfix(root, print_key);
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);


#endif
    return 0;
}