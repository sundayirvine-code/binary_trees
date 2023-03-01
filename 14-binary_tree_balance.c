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
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Balance factor of the binary tree (0 if tree is NULL).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    /* If tree is NULL, return 0 */
    if (!tree)
        return (0);

    /* Compute the height of the left and right subtrees */
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    /* Return the difference between the heights of the left and right subtrees */
    return (left_height - right_height);
}