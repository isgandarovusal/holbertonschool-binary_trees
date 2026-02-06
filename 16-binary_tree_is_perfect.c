#include "binary_trees.h"

/**
 * check_perfect - Helper to check if tree is perfect
 * @tree: Current node
 * @depth: Current depth
 * @leaf_level: First leaf level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int check_perfect(const binary_tree_t *tree, int depth, int *leaf_level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
	{
		if (*leaf_level == -1)
		{
			*leaf_level = depth;
			return (1);
		}
		return (depth == *leaf_level);
	}

	if (!tree->left || !tree->right)
		return (0);

	return (check_perfect(tree->left, depth + 1, leaf_level) &&
		check_perfect(tree->right, depth + 1, leaf_level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level = -1;

	if (!tree)
		return (0);

	return (check_perfect(tree, 0, &leaf_level));
}
