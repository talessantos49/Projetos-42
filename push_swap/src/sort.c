/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:44 by marvin            #+#    #+#             */
/*   Updated: 2023/04/12 15:52:17 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->first->data > stack->first->next->data)
		swap_a(stack);
}

void	sort_three(t_stack *stacka)
{
	int	next;
	int	last;

	next = stacka->first->next->data;
	last = last_number(stacka);
	if (next > stacka->first->data && last < next && last < stacka->first->data)
		shift_down_rra(stacka);
	else if (last > next && next > stacka->first->data)
	{
		shift_up_ra(stacka);
		swap_a(stacka);
	}
	else if (last > next && last > stacka->first->data
		&& stacka->first->data > next)
		swap_a(stacka);
	else
		sort_three_last(stacka);
}

void	push_three(t_stack *stacka, t_stack *stackb)
{	
	push_b(stacka, stackb);
	sort_three(stacka);
	push_a(stacka, stackb);
}

void	sort_four_last(t_stack *stacka, t_stack *stackb)
{
	int		first_a;
	int		next_a;
	int		next_a2;
	int		last_a;
	t_node	*aux;

	first_a = stacka->first->data;
	next_a = stacka->first->next->data;
	next_a2 = stacka->first->next->next->data;
	aux = last_node(stacka);
	last_a = aux->data;
	if (next_a < first_a && first_a < next_a2 && first_a < last_a
		&& next_a2 < last_a)
		swap_a(stacka);
	else if (next_a < first_a && next_a < last_a && next_a < next_a2)
		swap_push(stacka, stackb);
	else if (next_a2 < last_a && last_a < first_a && first_a < next_a)
		double_rra(stacka);
	else if (next_a2 < first_a && next_a2 < last_a && next_a2 < next_a)
	{
		double_rra(stacka);
		push_three(stacka, stackb);
	}	
}

void	sort_four(t_stack *stacka, t_stack *stackb)
{
	int		first_a;
	int		next_a;
	int		next_a2;
	int		last_a;
	t_node	*aux;

	first_a = stacka->first->data;
	next_a = stacka->first->next->data;
	next_a2 = stacka->first->next->next->data;
	aux = last_node(stacka);
	last_a = aux->data;
	if (first_a < next_a && first_a < next_a2 && first_a < last_a)
		push_three(stacka, stackb);
	else if (last_a < first_a && first_a < next_a && next_a < next_a2)
		shift_down_rra(stacka);
	else if (last_a < first_a && last_a < next_a && last_a < next_a2)
	{
		shift_down_rra(stacka);
		push_three(stacka, stackb);
	}
	else
		sort_four_last(stacka, stackb);
}
