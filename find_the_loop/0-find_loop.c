#include "lists.h"

/**
 * find_listint_loop - finds the start of a loop in a linked list
 * @head: pointer to the head of the list
 * Return: address of node where loop starts, or NULL if no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow, *fast;

    if (head == NULL)
        return (NULL);

    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow);
        }
    }

    return (NULL);
}
