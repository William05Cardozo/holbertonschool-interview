#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

/**
 * SWAP_TREE_NODE - macro that can be used to swap a node if binary tree
 *
 * @PARENT: parent of node that is being swapped
 * @NODE: node that is being swapped
 * @HEAD: node that use to reference the root node of binary tree
 *
 */
#define SWAP_TREE_NODE(PARENT, NODE, HEAD)                       \
	do {                                                         \
		heap_t _tmp_parent = {0, NULL, NULL, NULL};              \
		_tmp_parent.left = (PARENT)->left;                       \
		_tmp_parent.right = (PARENT)->right;                     \
		_tmp_parent.parent = (PARENT)->parent;                   \
		if ((PARENT)->left == (NODE))                            \
			_tmp_parent.left = (PARENT);                         \
		else if ((PARENT)->right == (NODE))                      \
			_tmp_parent.right = (PARENT);                        \
		(PARENT)->left = (NODE)->left;                           \
		(PARENT)->right = (NODE)->right;                         \
		(PARENT)->parent = (NODE);                               \
		if ((PARENT)->right)                                     \
			(PARENT)->right->parent = (PARENT);                  \
		if ((PARENT)->left)                                      \
			(PARENT)->left->parent = (PARENT);                   \
		(NODE)->left = _tmp_parent.left;                         \
		(NODE)->right = _tmp_parent.right;                       \
		(NODE)->parent = _tmp_parent.parent;                     \
		if ((NODE)->right)                                       \
			(NODE)->right->parent = (NODE);                      \
		if ((NODE)->left)                                        \
			(NODE)->left->parent = (NODE);                       \
		if ((NODE)->parent && (NODE)->parent->left == (PARENT))  \
			(NODE)->parent->left = (NODE);                       \
		if ((NODE)->parent && (NODE)->parent->right == (PARENT)) \
			(NODE)->parent->right = (NODE);                      \
		if (!(NODE)->parent)                                     \
			(HEAD) = (NODE);                                     \
	} while (0)

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
int len_btree(heap_t **tree);

#endif
