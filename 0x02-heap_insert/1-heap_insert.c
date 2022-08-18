#include "binary_trees.h"

/**
 * len_btree - length of the binary tree
 *
 * @tree: the binary tree
 *
 * Return: the length of the binary tree
 */
int len_btree(heap_t **tree)
{
	/**
	 * len_btree:: (tree) | tree == NULL | *tree == NULL -> 0
	 */
	if (!tree || !*tree)
	{
		return (0);
	}

	/**
	 * len_btree:: (*{left, right}) -> len_btree(left) + len_btree(right) + 1
	 */
	return (len_btree(&((*tree)->left)) + len_btree(&((*tree)->right)) + 1);
}

/**
 * get_parent - Get the parent node
 *
 * @root: the root node of the binary tree
 * @index: the index base to search
 */
void get_parent(heap_t **root, int index)
{
	int parent = (index - 1) / 2;
	/*
     * array_to_binary_tree:: (NULL, array, 0) -> void
     */
	if (!root || index == 0)
	{
		return;
	}

	/**
     * array_to_binary_tree:: (root, array, size) -> void
     */
	get_parent(root, parent);
	if (parent > 0 && !(parent % 2))
	{
		(*root) = (*root)->right;
	}
	if (parent > 0 && parent % 2)
	{
		(*root) = (*root)->left;
	}
}

/**
 * insert_from - insert a new node from the given parent
 *
 * @head: the head node
 * @parent: the parent node
 * @node: the node to insert into the binary tree
 */
void insert_from(heap_t **head, heap_t *parent, heap_t *node)
{
	/**
	 * insert_from:: (head, *parent, *node)
	 *                | parent == NULL
	 *                | node->n < parent->n
	 *                -> void
	 */
	if (!parent || node->n < parent->n)
		return;

	/**
	 * insert_from:: (head, NULL, *parent, *node) -> void
	 */
	SWAP_TREE_NODE(parent, node, *head);
	insert_from(head, node->parent, node);
}

/**
 * heap_insert - insert a node into the heap using max
 *
 * @root: the root node
 * @value: the value to insert
 *
 * Return: the node that was inserted into the binary tree
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = *root;
	int index = len_btree(root);

	/**
     * heap_insert:: (NULL, value) -> NULL
     */
	if (!root)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = new_node->left = new_node->right = NULL;
	/**
     * heap_insert:: (*NULL, value) -> heap_t
     */
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	/**
     * heap_insert:: (*root, value) -> heap_t
     */
	get_parent(&parent, index);
	new_node->parent = parent;
	if (!parent->left)
	{
		parent->left = new_node;
	}
	else
	{
		parent->right = new_node;
	}
	insert_from(root, parent, new_node);
	return (new_node);
}
