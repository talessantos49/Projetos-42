#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int    main(void)
{
    int        fd_lista_compras;
	// int        fd_lista_compras2;
    char    *line;
	// char    *line2;

    // Pedir ao sistema um identificador númerico(fd) que representa o arquivo
    fd_lista_compras = open("./lista_compras", O_RDONLY);
	// fd_lista_compras2 = open("./lista_compras2", O_RDONLY);
     printf("fd = %d\n", fd_lista_compras);
	// printf("fd = %d\n", fd_lista_compras2);

    while(1)
    {
        line = get_next_line(fd_lista_compras);		
        // line2 = get_next_line(fd_lista_compras2);
        if (line == NULL)
        {
            return (1);
        }
		// if (line2 == NULL)
        // {
        //     return (1);
        // }
        printf("line1 = %s", line);
        // printf("line2 = %s", line2);
        free(line);
    }
    line = get_next_line(fd_lista_compras);
    printf("line = %s", line);
    return (0);
}