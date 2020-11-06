#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/* int main(int argc, char **argv)
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
} */

int main(int argc, char **argv)
{
	int res1 = 0;
	int res2 = 0;
	int res3 = 0;
	int fd1;
	int fd2;
	int fd3;
	int line_count1 = 0;
	int line_count2 = 0;
	int line_count3 = 0;
	char *line;

	if (argc >= 2 && argc <= 4)
	{
		if (argc >= 2)
		{
			res1 = 1;
			fd1 = open(argv[1], O_RDONLY);
		}
		if (argc >= 3)
		{
			res2 = 2;
			fd2 = open(argv[2], O_RDONLY);
		}
		if (argc >= 4)
		{
			res3 = 3;
			fd3 = open(argv[3], O_RDONLY);
		}
		while (res1 != 0 || res2 != 0 || res3 != 0)
		{
			if (argc >= 2 && res1 != 0)
			{
				res1 = get_next_line(fd1, &line);
				printf("[return: %d] line1#%4d: %s$\n", res1, ++line_count1, line);
				free(line);
				line = NULL;
			}
			if (argc >= 3 && res2 != 0)
			{
				res2 = get_next_line(fd2, &line);
				printf("[return: %d] line2#%4d: %s$\n", res2, ++line_count2, line);
				free(line);
				line = NULL;
			}
			if (argc >= 4 && res3 != 0)
			{
				res3 = get_next_line(fd3, &line);
				printf("[return: %d] line3#%4d: %s$\n", res3, ++line_count3, line);
				free(line);
				line = NULL;
			}
		}
		if (argc >=2)
			close(fd1);
		if (argc >=3)
			close(fd2);
		if (argc >=4)
			close(fd3);
	}
	else if (argc == 1)
	{
		while ((res1 = get_next_line(0, &line)) > 0)
			printf("[Return: %d] Line#%4d: %s\n", res1, ++line_count1, line);
		if (res1 == -1)
			printf("Error\n");
		else if (res1 == 0)
			printf("\nEnd of stdin\n");
	}
	while (1){}
	return (0);
}
