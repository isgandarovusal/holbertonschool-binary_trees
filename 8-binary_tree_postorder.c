#include "binary_trees.h"

/**
 * binary_tree_postorder - Post-order traversal
 * @tree: Pointer to root node
 * @func: Pointer to callback function
 *
 * Description: Value in node passed to func.
 *              If tree or func NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
