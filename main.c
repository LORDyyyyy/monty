#include "monty.h"

/**
 * main - Entry point
 * @av: argument list
 * @ac: av len
 *
 * Return: always EXIT_SUCCESS
 */
int main(int ac, char **av)
{
	data_t data_struct, *data = &data_struct;
	int top = 0;
	stack_t *stack;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	get_args(av, data);
	return (EXIT_SUCCESS);
}
