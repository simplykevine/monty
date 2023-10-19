#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
 
stk_t *add_dnodeint_end(stk_t **head, const int n)
{
	stk_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stk_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stk_t *add_dnodeint(stk_t **head, const int n)
{
	stk_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stk_t));
	if (!temp)
	{
		vprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint(stk_t *head)
{
	stk_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
