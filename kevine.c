#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

stack_t *stack = NULL;
void push(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = stack;
    if (stack != NULL)
        stack->prev = new_node;
    stack = new_node;
}

void pall()
{
    stack_t *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint()
{
    if (stack == NULL)
    {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack->n);
}

void pop()
{
    if (stack == NULL)
    {
        fprintf(stderr, "L<line_number>: can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
    stack_t *temp = stack;
    stack = stack->next;
    free(temp);
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    pall();
    pint(); 
    pop();  
    pall(); 

    return 0;
}

