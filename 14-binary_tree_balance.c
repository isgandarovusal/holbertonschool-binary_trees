#include "binary_trees.h"

/**
 * height_for_balance - Measures height for balance calculation
 * @tree: Pointer to the root node
 *
 * Return: Height where NULL = 0, leaf = 1
 */
int height_for_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height_for_balance(tree->left);
	right_height = height_for_balance(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure balance factor
 *
 * Return: Balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (height_for_balance(tree->left) - height_for_balance(tree->right));
}
