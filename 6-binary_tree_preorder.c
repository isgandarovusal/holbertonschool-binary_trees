#include "binary_trees.h"

/**
 * binary_tree_preorder - Pre-order traversal
 * @tree: Pointer to root node
 * @func: Pointer to callback function
 *
 * Description: Value in node passed to func.
 *              If tree or func NULL, do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
