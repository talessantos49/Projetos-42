/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/17 18:50:11 by tasantos         ###   ########.fr       */
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

void	free_all(t_stack *stacka, t_stack *stackb)
{
	if (stacka->first)
		free_stack(stacka);
	if (stackb->first)
		free_stack(stackb);
}

void	free_stack(t_stack *stack)
{
	t_node	*aux;
	t_node	*last;

	aux = NULL;
	last = NULL;
	if (stack->first->next == NULL)
		free(stack->first);
	else
	{		
		aux = stack->first->next;
		free(stack->first);
		stack->first = aux;
		free_stack(stack);
	}
	free(last);
}

void	free_node(t_node *node)
{
	t_node	*node_temp;

	if (node)
		return ;
	while (node)
	{
		node_temp = node->next;
		free(node);
		node = node_temp;
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
	bigest_number(&stacka);
	if (argc == 3)
		sort_two(&stacka);
	else if (argc == 4)
		sort_three(&stacka);
	else if (argc == 5)
		sort_four(&stacka, &stackb);
	else if (argc == 6)
		sort_five(&stacka, &stackb);
	else
		quick_sort(&stacka, &stackb);
	free_all(&stacka, &stackb);
	return (0);
}
