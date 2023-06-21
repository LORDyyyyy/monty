#include "monty.h"


/*
 * get_args - get the arguments from monty file
 * and put it in the data_t struct
 *
 * @av: auguments, holds the file name, len(ac) = 2
 * @data: data_t struct that will hold the commands
 *
 * Retrun: void
 */
void get_args(char **av, data_t *data)
{
	data->prog_name = av[0];
	data->file_name = av[1];
	data->argc = 0;

	int line_count;
	
	line_count = get_line_count(data->file_name);
	printf("line count : %d\n", line_count);
}

/**
 * get_line_count - gets how many lines in monty file
 * ignoring the empty fiels
 * @file_name: the file name, taken from av[1]
 *
 * Retrun: line count
 */
int get_line_count(char *file_name)
{
	FILE *fptr;
	char arr[1024], *p;
	int flag = 0, line_count = 0;

	if (!(fptr = fopen(file_name, "r")))
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (!feof(fptr))
	{
		fgets(arr, 1024, fptr);
		p = arr;
		while (*p)
		{
			if (*p != 10 && *p != '\t' && *p != ' ')
			{
				printf("%c", *p);
				flag = 1;
			}
			p++;
		}
		if (flag)
		{
			printf("\n");
			line_count++;
		}
		flag = 0;
		strcpy(arr, "\0");
	}
	fclose(fptr);
	return (line_count);
}
