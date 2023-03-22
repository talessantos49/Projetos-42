/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:59:12 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 10:59:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_a(t_stack *stackA, t_stack *stackB){
	stack_up(stackA, stackB->first->data);
	unstack(stackB);
    write(1,"pa\n", 3);
}

void swap_a(t_stack *stackA){
	t_node *aux1 = NULL;
	t_node *aux2 = NULL;

	aux1 = unstack(stackA);
	aux2 = unstack(stackA);
	stack_up(stackA, aux1->data);
	stack_up(stackA, aux2->data);
    write(1, "sa\n", 3);
}

void shift_down_rra(t_stack *stack)
{	
	int aux;

	aux = stack->last->data;
	remove_list(stack, stack->last->data);
	insert_up(stack, aux);
    write(1, "rra\n", 4);
}

void shift_up_ra(t_stack *stack)
{
    shift_up(stack);
    write(1, "ra\n", 3);
}
