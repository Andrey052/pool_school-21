#ifndef BST_H
#define BST_H
#define MAXWORD 100

typedef struct tree {
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

node *create(node *root, int key);
node *bstree_create_node(node *root, int key);
void bstree_insert(node **root, int key, int (*cmpf)(int, int));
int compare_ints(int a, int b);
void bstree_apply_infix(node *root, void (*applyf) (int));
void bstree_apply_prefix(node *root, void (*applyf) (int));
void bstree_apply_postfix(node *root, void (*applyf) (int));
void print_key(int key);

#endif