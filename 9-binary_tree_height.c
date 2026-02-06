#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	/* Measure height of left subtree */
	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;

	/* Measure height of right subtree */
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the larger height */
	return (left_height > right_height ? left_height : right_height);
}
