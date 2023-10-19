#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stk_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stk_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stk_t **stack, unsigned int line_number);
} instruction_t;

extern global_t glovar;

/* opcode_instructuions*/
void _push(stk_t **stack, unsigned int line_number);
void _pall(stk_t **stack, unsigned int line_number);
void _pint(stk_t **doubly, unsigned int cline);
void _pop(stk_t **doubly, unsigned int cline);
void _swap(stk_t **doubly, unsigned int cline);
void _queue(stk_t **doubly, unsigned int cline);
void _stack(stk_t **doubly, unsigned int cline);
void _add(stk_t **doubly, unsigned int cline);
void _nop(stk_t **doubly, unsigned int cline);
void _sub(stk_t **doubly, unsigned int cline);
void _div(stk_t **doubly, unsigned int cline);
void _mul(stk_t **doubly, unsigned int cline);
void _mod(stk_t **doubly, unsigned int cline);
void _pchar(stk_t **doubly, unsigned int cline);
void _pstr(stk_t **doubly, unsigned int cline);
void _rotl(stk_t **doubly, unsigned int cline);
void _rotr(stk_t **doubly, unsigned int cline);

/*get function*/
void (*get_opcodes(char *opc))(stk_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_real(void *ptr, unsigned int old_size, unsigned int new_size);
void *_cancat(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stk_t *add_dnodeint_end(stk_t **head, const int n);
stk_t *add_dnodeint(stk_t **head, const int n);
void free_dlistint(stk_t *head);

/* main */
void free_vglo(void);

#endif
