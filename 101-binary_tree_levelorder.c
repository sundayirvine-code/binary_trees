#include "binary_trees.h"
#include <stdlib.h>

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

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *        The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue = NULL;
    int rear = -1, size = 0;

    if (!tree || !func)
        return;

    queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
    if (!queue)
        return;

    queue[++rear] = (binary_tree_t *)tree;

    while (size <= rear)
    {
        tree = queue[size++];
        func(tree->n);

        if (tree->left)
            queue[++rear] = tree->left;

        if (tree->right)
            queue[++rear] = tree->right;
    }

    free(queue);
}
