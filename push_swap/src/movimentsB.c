/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:32:33 by marvin            #+#    #+#             */
/*   Updated: 2023/04/11 02:26:55 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_stack *stackA, t_stack *stackB)
{
	stack_up(stackB, stackA->first->data);
	unstack(stackA);
	write(1, "pb\n", 3);
}

void	swap_b(t_stack *stackB)
{
	t_node	*aux1;
	t_node	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	aux1 = unstack(stackB);
	aux2 = unstack(stackB);
	stack_up(stackB, aux1->data);
	stack_up(stackB, aux2->data);
	write(1, "sb\n", 3);
}

void	shift_down_rrb(t_stack *stack)
{
	int	aux;

	aux = last_number(stack)->data;
	remove_list(stack, aux);
	stack_up(stack, aux);
	write(1, "rrb\n", 4);
}

void	shift_up_rb(t_stack *stack)
{
	shift_up(stack);
	write(1, "rb\n", 3);
}
