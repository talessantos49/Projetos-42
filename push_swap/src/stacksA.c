/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacksA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:52:22 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/17 15:53:05 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_down(t_stack *stack, int num)
{
	t_node	*new;

	new = create_node(num);
	if (new)
		add_node(stack, new);
}

t_node	*unstack(t_stack *stack)
{
	t_node	*remove;

	remove = NULL;
	if (stack->first)
	{
		remove = stack->first;
		stack->first = remove->next;
		return (remove);
	}
	return (NULL);
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
