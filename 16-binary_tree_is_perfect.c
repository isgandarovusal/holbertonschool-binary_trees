#include "binary_trees.h"

/**
 * check_perfect_recursive - Helper function to check if tree is perfect
 * @tree: Pointer to current node
 * @depth: Current depth
 * @leaf_level: Level of first leaf found
 *
 * Return: 1 if perfect, 0 otherwise
 */
int check_perfect_recursive(const binary_tree_t *tree, int depth, int *leaf_level)
{
	if (tree == NULL)
		return (1);

	/* Leaf node */
	if (tree->left == NULL && tree->right == NULL)
	{
		/* First leaf found */
		if (*leaf_level == -1)
		{
			*leaf_level = depth;
			return (1);
		}
		/* Check if leaf at same level as first leaf */
		return (depth == *leaf_level);
	}

	/* Internal node must have 2 children in perfect tree */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Check both subtrees recursively */
	return (check_perfect_recursive(tree->left, depth + 1, leaf_level) &&
		check_perfect_recursive(tree->right, depth + 1, leaf_level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level = -1;

	if (tree == NULL)
		return (0);

	return (check_perfect_recursive(tree, 0, &leaf_level));
}
