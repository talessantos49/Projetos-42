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

void	push_a(t_stack *stackA, t_stack *stackB)
{
	if (!stackB->first)
		return ;
	insert_up(stackA, stackB->first->data);
	remove_list(stackB, stackB->first->data);
	write(1, "pa\n", 3);
}

void	swap_a(t_stack *stackA)
{
	int		data1;
	int		data2;

	if (stackA->first == NULL || stackA->first->next == NULL)
		return ;
	if (stack_len(stackA) < 2)
		return ;
	data1 = stackA->first->data;
	data2 = stackA->first->next->data;
	remove_list(stackA, data1);
	remove_list(stackA, data2);
	insert_up(stackA, data1);
	insert_up(stackA, data2);
	write(1, "sa\n", 3);
}

void	shift_down_rra(t_stack *stack)
{
	int		aux;

	aux = last_number(stack);
	remove_list(stack, aux);
	insert_up(stack, aux);
	write(1, "rra\n", 4);
}

void	shift_up_ra(t_stack *stack)
{
	shift_up(stack);
	write(1, "ra\n", 3);
}
