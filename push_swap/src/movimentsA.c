/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:59:12 by marvin            #+#    #+#             */
/*   Updated: 2023/04/17 15:46:41 by tasantos         ###   ########.fr       */
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
	t_node	*aux1;
	t_node	*aux2;

	aux1 = unstack(stackA);
	aux2 = unstack(stackA);
	insert_up(stackA, aux1->data);
	insert_up(stackA, aux2->data);
	free(aux1);
	free(aux2);
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
