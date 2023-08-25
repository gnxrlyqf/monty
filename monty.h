#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct var_global - global structure
 * @stack: head of doubly linked list
 * @fd: file descriptor
 * @buffer: buffer
 * @cmd: split command
 * Description: struct whith global variables
 */
typedef struct var_global
{
	stack_t *stack;
	FILE *fd;
	char *buffer;
	char **cmd;
} var_g;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern var_g var_glb;


void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, __attribute__((unused)) unsigned int line_number);


void (*get_inst(char *opc))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void _free(void);
void cmd(char *buffer, int line_num);
int is_number(char *s);
#endif /* MONTY_H*/
