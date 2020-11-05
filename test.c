#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int main(int argc, char **argv)
{
	int fd[argc];
	int ret;
	int line_count;
	char *line;
	int i;

	i = 1;
	line_count = 0;
	if (argc >= 2)
	{
		while (i < argc)
		{
			line_count = 0;
			fd[i] = open(argv[i], O_RDONLY);
			printf("==============================\nfd=%d: %s\n==============================\n\n", fd[i], argv[i]);
			while ((ret = get_next_line(fd[i], &line)) > 0)
			{
				printf("[return: %d] line#%4d: %s$\n", ret, ++line_count, line);
				free(line);
				line = NULL;
			}
			printf("[return: %d] line#%4d: %s$\n", ret, ++line_count, line);
			if (ret == -1)
				printf("Error\n");
			else if (ret == 0)
				printf("\n\n");
			i++;
			free(line);
		}
	}
	else if (argc == 1)
	{
		while ((ret = get_next_line(0, &line)) > 0)
			printf("[Return: %d] Line#%4d: %s\n", ret, ++line_count, line);
		if (ret == -1)
			printf("Error\n");
		else if (ret == 0)
			printf("\nEnd of stdin\n");
	}
	while (argc > 0)
		close(fd[(argc--) - 1]);
	//while (1) {}
	return (0);
}

/* int main(int argc, char **argv)
{
	int fd[argc];
	int ret;
	int line_count1;
	int line_count2;
	char *line;
	int i;


	line_count1 = 0;
	line_count2 = 0;
	if (argc == 2)
	{
			fd[1] = open(argv[1], O_RDONLY);
			printf("==============================\nfd=%d: %s\n==============================\n\n", fd[1], argv[1]);
			while ((ret = get_next_line(fd[1], &line)) > 0 || (ret = get_next_line(fd[2], &line)) > 0)
			{
				printf("[return: %d] line#%4d: %s$\n", ret, ++line_count1, line);
				printf("[return: %d] line#%4d: %s$\n", ret, ++line_count2, line);
				free(line);
				line = NULL;
			}
			printf("[return: %d] line#%4d: %s$\n", ret, ++line_count1, line);
			printf("[return: %d] line#%4d: %s$\n", ret, ++line_count2, line);
			if (ret == -1)
				printf("Error\n");
			else if (ret == 0)
				printf("\n\n");
			i++;
			free(line);
	}
	else if (argc == 1)
	{
		while ((ret = get_next_line(0, &line)) > 0)
			printf("[Return: %d] Line#%4d: %s\n", ret, ++line_count, line);
		if (ret == -1)
			printf("Error\n");
		else if (ret == 0)
			printf("\nEnd of stdin\n");
	}
	while (argc > 0)
		close(fd[(argc--) - 1]);
	//while (1) {}
	return (0);
} */