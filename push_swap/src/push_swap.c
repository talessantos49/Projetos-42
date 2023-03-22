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

int    main(int argc, char **argv)
{
	t_stack stackA;
	t_stack stackB;

    if (argc < 2)
        return (ft_printf("Error\n"));
    checkers(argc, argv);
	create_stack(&stackA);
	create_stack(&stackB);

    return (0);
}