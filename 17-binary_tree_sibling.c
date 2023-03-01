#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: a pointer to the node to find the sibling of
 *
 * Return: a pointer to the sibling node, or NULL if node is NULL, node has no
 * sibling, or the parent of node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* If node is NULL or the parent is NULL, return NULL */
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* If node is the left child, return the right child; otherwise, return
       the left child. If node is not a child of its parent, return NULL */
    if (node->parent->left == node)
        return (node->parent->right);

    if (node->parent->right == node)
        return (node->parent->left);

    return (NULL);
}
