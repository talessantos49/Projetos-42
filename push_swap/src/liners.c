/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liners.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:10:24 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:38 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	double_rra(t_stack *stacka)
{
	shift_down_rra(stacka);
	shift_down_rra(stacka);
}

void	swap_push(t_stack *stacka, t_stack *stackb)
{
	swap_a(stacka);
	push_three(stacka, stackb);
}

void	sort_three_last(t_stack *stacka)
{
	int	next;
	int	last;

	next = stacka->first->next->data;
	last = last_number(stacka);
	if (next > last && last > stacka->first->data)
	{
		swap_a(stacka);
		shift_up_ra(stacka);
	}
	else if (stacka->first->data > last && last > next)
		shift_up_ra(stacka);
	else if (stacka->first->data > next && next > last)
	{
		swap_a(stacka);
		shift_down_rra(stacka);
	}
}
