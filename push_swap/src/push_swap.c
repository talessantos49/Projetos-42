/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:33:40 by tasantos          #+#    #+#             */
/*   Updated: 2023/02/13 22:06:13 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void    check_arguments(int argc, char **argv)
{
    int i;
    int k;
    int is_num;
    int len;
    long long int enter_argument;

    i = 0;
    k = -1;
    enter_argument = 0;
    is_num = 0;
    while (i < argc)
    {
        ft_printf("teste: %i\n", argv[i][k++]);
        len = ft_strlen(argv[i]);
        ft_printf("len: %i\n", len);
        while (k++ < len)
        {
            is_num = ft_isdigit(argv[i][k]);
            ft_printf("is_num = %c\n",is_num);   
        }
        enter_argument = ft_atoi (argv[i]);
        if (is_num == 1)
            ft_printf("Error: Invalid type of argument, please put a number\n");
        if (enter_argument >= INT_MAX)
            enter_argument = (INT_MAX);
        if (enter_argument <= INT_MIN)
            enter_argument = INT_MIN;
        if (enter_argument == INT_MAX)
            ft_printf("Error: Enter a valid argument number.\n");
        if (enter_argument == INT_MIN)
            ft_printf("Error: Enter a valid argument number Interger Overflow.\n");
        i++;
        k = 0;
    }
}

int main (int argc, char **argv)
{
    check_arguments (argc, argv);
}
