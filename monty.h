#ifndef MONTY
#define MONTY



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int top;


/**
 * struct data_s - the struct that will hold the commands from the monty file
 * @args: commands
 * @argc: commands count
 * @prog_name: the executable file name
 * @file_name: the monty file name
 *
 */

typedef struct data_s
{
	char **args;
	char *prog_name;
	char *file_name;
	int argc;
} data_t;


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


/*	args.c - handle the arguments	*/

void get_args(char **av, data_t *data);

int get_line_count(char *file_name);

/*		end	args.c		*/



#endif
