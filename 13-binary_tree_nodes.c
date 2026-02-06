#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in binary tree
 * @tree: Pointer to root node of tree to count nodes
 *
 * Return: Number of nodes with at least 1 child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* If node has at least one child */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	/* Node has no children (leaf) */
	return (0);
}
