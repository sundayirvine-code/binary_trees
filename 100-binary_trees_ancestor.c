#include <stdlib.h>
#include "binary_trees.h"

/**
 * struct Node - linked list structure for ancestors
 * @ancestor: pointer to ancestor node
 * @next: pointer to next node in the list
 */
typedef struct Node
{
    binary_tree_t *ancestor;
    struct Node *next;
} Node;

/**
 * create_list - Adds a new node in the linked list
 * @head: pointer to the head node of the linked list
 * @ancestor: pointer to the ancestor node to be added to the list
 *
 * Return: pointer to the head node of the linked list
 */
Node *create_list(Node *head, binary_tree_t *ancestor)
{
    Node *temp = head;

    /* Create new node */
    Node *new_node = malloc(sizeof(Node));
    if (!new_node)
        return (NULL);
    new_node->ancestor = ancestor;
    new_node->next = NULL;

    /* Insert node */
    if (!head)
        head = new_node;
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    return (head);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    binary_tree_t *parent1 = first->parent;
    binary_tree_t *parent2 = second->parent;
    Node *head = NULL;
    Node *temp;

    /* Check for NULL input */
    if (first == NULL || second == NULL)
        return (NULL);

    /* Check for immediate parent-child relationship */
    if (second->parent == first)
        return (parent2);
    if (first->parent == second)
        return (parent1);

    /* Loop through first's parents and add to linked list */
    while (parent1)
    {
        head = create_list(head, parent1);
        parent1 = parent1->parent;
    }

    /* Check if second's parents are in the linked list */
    while (parent2)
    {
        temp = head;

        /* Loop through the linked list to find the common ancestor */
        while (temp)
        {
            if (temp->ancestor == parent2)
                return (parent2);
            temp = temp->next;
        }

        parent2 = parent2->parent;
    }

    /* No common ancestor was found */
    return (NULL);
}