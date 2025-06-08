#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to pointer to the head node
 * @n: integer to add
 * Return: address of the new element, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new_node;

    if (head == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;

    return (new_node);
}

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head node
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow, *fast;
    size_t count = 0;

    slow = head;
    fast = head;

    while (fast && fast->next)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        count++;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("-> [%p] %d\n", (void *)slow, slow->n);
            break;
        }
    }
    if (!fast || !fast->next)
    {
        while (slow)
        {
            printf("[%p] %d\n", (void *)slow, slow->n);
            count++;
            slow = slow->next;
        }
    }
    return (count);
}

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: pointer to pointer to head
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *slow, *fast, *tmp;
    size_t count = 0;

    if (!h || !*h)
        return (0);

    slow = *h;
    fast = *h;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = *h;
            while (slow != fast)
            {
                tmp = slow;
                slow = slow->next;
                free(tmp);
                count++;
            }
            while (fast)
            {
                tmp = fast;
                fast = fast->next;
                free(tmp);
                count++;
            }
            *h = NULL;
            return (count);
        }
    }

    // No loop detected: free normally
    while (*h)
    {
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
    }

    return (count);
}
