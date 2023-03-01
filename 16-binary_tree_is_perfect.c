#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    /* If tree is NULL, return 0 */
    if (!tree)
        return (0);

    /* Recursively compute the height of the left and right subtrees */
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    /* Return the maximum of the left and right subtree heights plus 1 (to include the current node) */
    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    /* If tree is NULL, return 0 */
    if (!tree)
        return (0);

    /* If the tree is a leaf, it is perfect by definition */
    if (!tree->left && !tree->right)
        return (1);

    /* If the tree has only one child, it is not perfect */
    if (!tree->left || !tree->right)
        return (0);

    /* Recursively check if both subtrees are perfect */
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height == right_height)
        return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));

    return (0);
}
