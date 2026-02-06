#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts node as right-child of another node
 * @parent: Pointer to node to insert right-child in
 * @value: Value to store in new node
 *
 * Return: Pointer to created node, or NULL on failure or if parent is NULL
 *
 * Description: If parent already has right-child, new node takes its place,
 *              and old right-child becomes right-child of new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
