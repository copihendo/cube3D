#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int gnl(char **line)
{
    int i = 0;
    int rd;
    char ch;
    char *buffer = malloc(100000);
    *line = buffer;
    while((rd = read(0, &ch, 1)) > 0 && ch != '\n')
        buffer[i++] = ch;
    buffer[i] = '\0';
    return(rd);
}

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1

int gnl(char **line);

#endif

int get_next_line( char **line)
{
	int i = 0;
	int rd;
	char ch;
	char *buffer = malloc(100000);

	*line = buffer;
	while((rd=read(0, &ch, 1)) > 0 && ch != '\n')
		buffer[i++] = ch;
	buffer[i] = '\0';
	return (rd);
}

