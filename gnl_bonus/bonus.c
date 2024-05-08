#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int f1 = open("b1.txt", O_RDONLY);
    int f2 = open("b2.txt", O_RDONLY);;
    int f3 = open("b3.txt", O_RDONLY);;
    int f4 = open("b4.txt", O_RDONLY);;

    char *line;
    for(int i = 0; i < 8; i++)
    {
        line = get_next_line(f1);
        printf("%s", line);
        free(line);
        line = get_next_line(f2);
        printf("%s", line);
        free(line);
        line = get_next_line(f3);
        printf("%s", line);
        free(line);
        line = get_next_line(f4);
        printf("%s", line);
        free(line);
    }
}
   
//cc -Wextra -Werror -Wall -g -fsanitize=address get_next_line_bonus.c get_next_line_utils_bonus.c bonus.c
