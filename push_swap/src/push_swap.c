/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:08 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi_push(const char	*str)
{
    long int        i;
	long int        negative;
	long long int   num;

	i = 0;
	num = 0;
	negative = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * negative);
}

int    main(int argc, char **argv)
{
	t_stack stackA;
	t_stack stackB;

    if (argc < 2)
        return (ft_printf("Error\n"));
    checkers(argc, argv);
    ft_printf("Need ordenation!\n");
	create_stack(&stackA);
	create_stack(&stackB);

    return (0);
}