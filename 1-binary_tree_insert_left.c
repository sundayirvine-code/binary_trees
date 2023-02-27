#include <stdlib.h>
#include "binary_trees.h"


/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the new node or NULL if fails.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node, *temp;

    if (!parent)
        return (NULL);

    new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent->left)
    {
        temp = parent->left;
        parent->left = new_node;
        new_node->left = temp;
        temp->parent = new_node;
    }
    else
        parent->left = new_node;

    return (new_node);
}