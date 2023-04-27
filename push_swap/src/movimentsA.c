/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:59:12 by marvin            #+#    #+#             */
/*   Updated: 2023/04/21 21:13:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *stacka, t_stack *stackb)
{
	int	index_b;

	if (!stackb->first)
		return ;
	index_b = stackb->first->index;
	insert_up(stacka, stackb->first->data);
	remove_list(stackb, stackb->first->data);
	stacka->first->index = index_b;
	stacka->last = last_node(stacka);
	stackb->last = last_node(stackb);
	write(1, "pa\n", 3);
}

void	swap_a(t_stack *stacka)
{
	int		data1;
	int		data2;
	int		index1;
	int		index2;

	if (stacka->first == NULL || stacka->first->next == NULL)
		return ;
	if (stack_len(stacka) < 2)
		return ;
	index1 = stacka->first->index;
	index2 = stacka->first->next->index;
	data1 = stacka->first->data;
	data2 = stacka->first->next->data;
	remove_list(stacka, data1);
	remove_list(stacka, data2);
	insert_up(stacka, data1);
	insert_up(stacka, data2);
	stacka->first->index = index2;
	stacka->first->next->index = index1;
	stacka->last = last_node(stacka);
	write(1, "sa\n", 3);
}

void	shift_down_rra(t_stack *stack)
{
	int		aux;
	int		index;

	aux = last_number(stack);
	index = stack->last->index;
	remove_list(stack, aux);
	insert_up(stack, aux);
	stack->first->index = index;
	stack->last = last_node(stack);
	write(1, "rra\n", 4);
}

void	shift_up_ra(t_stack *stack)
{
	int	index;

	index = stack->first->index;
	shift_up(stack);
	stack->last = last_node(stack);
	stack->last->index = index;
	write(1, "ra\n", 3);
}
