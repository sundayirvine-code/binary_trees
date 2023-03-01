#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of leaves in the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t right, left;

    if (!tree)
        return (0);

    if (!(tree -> left) && !(tree -> right))
        return (1);

    left = binary_tree_leaves(tree->left);
    right = binary_tree_leaves(tree->right);
    return (left + right);

    
    
}