/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/11 03:16:09 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi_push(const char	*str)
{
	long long int	num;
	long int		i;
	long int		negative;

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

void	initial_stack(t_stack *stacka, int argc, char *argv[])
{
	long long int	value;
	int				i;

	i = 1;
	value = 0;
	while (i < argc)
	{
		value = ft_atoi_push(argv[i]);
		insert_down(stacka, value);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stacka;
	t_stack	stackb;

	if (argc < 2)
		return (0);
	checkers(argc, argv);
	create_stack(&stacka);
	create_stack(&stackb);
	initial_stack(&stacka, argc, argv);
	if (argc == 3)
		sort_two(&stacka);
	else if (argc == 4)
		sort_three(&stacka);
	else if (argc == 5)
		sort_four(&stacka, &stackb);
	else if (argc == 6)
		sort_five(&stacka, &stackb);
	return (0);
}
/*
void imprimir_pilha(t_stack *stacka)
{
	t_node *aux;
	
	aux = stacka->first;
    while(aux)
	{
		ft_printf("[%d]->", aux->data);
		aux = aux->next;
	}
    ft_printf("\n-----------------------------\n");
}*/
