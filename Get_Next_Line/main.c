#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int    main(void)
{
    int        fd_lista_compras;
    char    *line;

    // Pedir ao sistema um identificador númerico(fd) que representa o arquivo
    fd_lista_compras = open("./lista_compras", O_RDONLY);
    printf("fd = %d\n", fd_lista_compras);

    while(1)
    {
        line = get_next_line(fd_lista_compras);
        if (line == NULL)
        {
            return (1);
        }
        printf("line = %s", line);
        free(line);
    }
    line = get_next_line(fd_lista_compras);
    printf("line = %s", line);
    return (0);
}