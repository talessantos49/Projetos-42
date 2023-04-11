/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:59:12 by marvin            #+#    #+#             */
/*   Updated: 2023/04/11 03:47:07 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *stackA, t_stack *stackB)
{
	stack_up(stackA, stackB->first->data);
	unstack(stackB);
	write(1, "pa\n", 3);
}

void	swap_a(t_stack *stackA)
{
	t_node	*aux1;
	t_node	*aux2;

	aux2 = NULL;
	aux1 = NULL;
	aux1 = unstack(stackA);
	aux2 = unstack(stackA);
	stack_up(stackA, aux1->data);
	stack_up(stackA, aux2->data);
	write(1, "sa\n", 3);
}

void	shift_down_rra(t_stack *stack)
{	
	int	aux;

	aux = last_number(stack)->data;
	remove_list(stack, aux);
	stack_up(stack, aux);
	write(1, "rra\n", 4);
}

void	shift_up_ra(t_stack *stack)
{
	shift_up(stack);
	write(1, "ra\n", 3);
}
