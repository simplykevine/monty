#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _push(stk_t **doubly, unsigned int cline)
{
	int n, j;

	if (!glovar.arg)
	{
		vprintf(2, "L%u: ", cline);
		vprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glovar.arg[j] != '\0'; j++)
	{
		if (!isdigit(glovar.arg[j]) && glovar.arg[j] != '-')
		{
			vprintf(2, "L%u: ", cline);
			vprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glovar.arg);

	if (glovar.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * _pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void _pall(stk_t **doubly, unsigned int cline)
{
	stk_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		vprintf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pint(stk_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		vprintf(2, "L%u: ", cline);
		vprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _pop(stk_t **doubly, unsigned int cline)
{
	stk_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		vprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _swap(stk_t **doubly, unsigned int cline)
{
	int m = 0;
	stk_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		vprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
