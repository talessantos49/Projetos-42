/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 02:54:45 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/17 15:57:30 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_ordenaded(t_stack *stackA)
{
	int	first_a;
	int	next_a;
	int	next_a2;
	int	next_a3;
	int	last_a;

	first_a = stackA->first->data;
	next_a = stackA->first->next->data;
	next_a2 = stackA->first->next->next->data;
	next_a3 = stackA->first->next->next->next->data;
	last_a = last_number(stackA);
	if (first_a < next_a && next_a < next_a2
		&& next_a2 < next_a3 && next_a3 < last_a)
		return (1);
	return (0);
}

t_node	*last_node(t_stack *stack)
{
	t_node	*aux;

	aux = stack->first;
	while (aux->next)
		aux = aux->next;
	return (aux);
}

int	last_number(t_stack *stack)
{
	t_node	*aux;

	aux = stack->first;
	while (aux->next)
		aux = aux->next;
	return (aux->data);
}

void	sort_five(t_stack *stackA, t_stack *stackB)
{
	t_node	*aux;
	int		min;

	min = stackA->first->data;
	aux = stackA->first;
	while (aux->next)
	{
		if (min > aux->next->data)
			min = aux->next->data;
		aux = aux->next;
	}
	while (stackA->first->data != min)
		shift_up_ra(stackA);
	if (is_ordenaded(stackA))
		exit(1);
	push_b(stackA, stackB);
	sort_four(stackA, stackB);
	push_a(stackA, stackB);
}
