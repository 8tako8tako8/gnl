#include "get_next_line.h"
/*
int        main(int ac, char **av)
{
     int        fd;
     char    *line;
     int        flag;

     (void)ac;
     fd = open(av[1], O_RDONLY);
     while ((flag = get_next_line(fd, &line)) == 1)
     {
         write(1, line, ft_strlen(line));
         write(1, "\n", 1);
         free(line);
     }
     if (flag == -1)
         write(2, "get_next_line_error", 20);
     write(1, line, ft_strlen(line));
     free(line);
     close(fd);
     return (0);
 }
*/
// #include <stdio.h>

// int main()
// {
//     char *line;
//      get_next_line(0,&line);
//         printf("%s\n",line);

// }

#include <stdio.h>

int main()
{
    char *str;
    int fd = open("./sample.txt", O_RDONLY);
    if (fd < 0) {
        printf("\033[1;31mCould not open file\n");
        return 0377;
    }
    while(get_next_line(fd, &str))
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
        free(str);
    }
    fd = open("./sample2.txt", O_RDONLY);
    if (fd < 0) {
        printf("\033[1;31mCould not open file\n");
        return 0377;
    }
    while(get_next_line(fd, &str))
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
        free(str);
    }
    free(str);
}
