#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is full, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    /* If tree is NULL, return 0 */
    if (!tree)
        return (0);

    /* If the tree is a leaf, it is full by definition */
    if (!tree->left && !tree->right)
        return (1);

    /* If the tree has two children, recursively check if both subtrees are full */
    if (tree->left && tree->right)
        return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

    /* If the tree has only one child, it is not full */
    return (0);
}
