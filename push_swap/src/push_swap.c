/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:33:40 by tasantos          #+#    #+#             */
/*   Updated: 2023/02/13 21:07:23 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void check_arguments(int argc, char **argv)
{
    int i;
    long int enter_argument;

    i = 0;
    enter_argument = 0;
    while (i < argc)
    {
        enter_argument = ft_atoi(argv[i]);
        if (enter_argument >= INT_MAX)
            ft_printf("Error: Enter a valid argument number.");
        if (enter_argument <= INT_MIN)
            ft_printf("Error: Enter a valid argument number!");
        i++;
    }
}

int main(int argc, char **argv)
{
    check_arguments(argc, argv);
}