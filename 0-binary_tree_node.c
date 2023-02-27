#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 *
 * @parent: A pointer to the parent node.
 * @value: The integer value to be stored in the new node.
 *
 * Return: A pointer to the new binary tree node, or NULL if memory allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    /*Create new node and allocate memory*/
    binary_tree_t *new_node;
    new_node = malloc(sizeof(binary_tree_t));

    /* Check for memory allocation errors */
    if (!new_node)
    {
        return (NULL);
    }

    /* Initialize the new node with the given value and parent */
    new_node -> n = value;
    new_node -> parent = parent;
    new_node -> left = NULL;
    new_node -> right = NULL;

    /* Return a pointer to the new node */
    return (new_node);
}