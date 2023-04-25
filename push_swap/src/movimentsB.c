/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:32:33 by marvin            #+#    #+#             */
/*   Updated: 2023/04/21 21:41:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_stack *stacka, t_stack *stackb)
{
	if (!stacka->first)
		return ;
	insert_up(stackb, stacka->first->data);
	remove_list(stacka, stacka->first->data);
	stacka->last = last_node(stacka);
	stackb->last = last_node(stackb);
	write(1, "pb\n", 3);
}

void	swap_b(t_stack *stackb)
{
	int		data1;
	int		data2;

	if (stackb->first == NULL || stackb->first->next == NULL)
		return ;
	if (stack_len(stackb) < 2)
		return ;
	data1 = stackb->first->data;
	data2 = stackb->first->next->data;
	remove_list(stackb, data1);
	remove_list(stackb, data2);
	insert_up(stackb, data1);
	insert_up(stackb, data2);
	stackb->last = last_node(stackb);
	write(1, "sb\n", 3);
}

void	shift_down_rrb(t_stack *stack)
{
	int		aux;

	aux = last_number(stack);
	remove_list(stack, aux);
	insert_up(stack, aux);
	stack->last = last_node(stack);
	write(1, "rrb\n", 4);
}

void	shift_up_rb(t_stack *stack)
{
	shift_up(stack);
	stack->last = last_node(stack);
	write(1, "rb\n", 3);
}
