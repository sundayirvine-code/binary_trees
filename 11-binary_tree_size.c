#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Calculates the size of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to measure.
 *
 * Return: Size of binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    size_t left, right;

    if (!tree)
        return (0);

    left = binary_tree_size(tree->left);
    right = binary_tree_size(tree->right);
    return (left + right + 1);
}