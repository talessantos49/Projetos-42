/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:32:33 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 11:32:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_b(t_stack *stackA, t_stack *stackB){
	stack_up(stackB, stackA->first->data);
	unstack(stackA);
    write(1,"pb\n", 3);
}

void swap_b(t_stack *stackB){
	t_node *aux1 = NULL;
	t_node *aux2 = NULL;

	aux1 = unstack(stackB);
	aux2 = unstack(stackB);
	stack_up(stackB, aux1->data);
	stack_up(stackB, aux2->data);
    write(1, "sb\n", 3);
}

void shift_down_rrb(t_stack *stack)
{	
	int aux;

	aux = stack->last->data;
	remove_list(stack, stack->last->data);
	insert_up(stack, aux);
    write(1, "rrb\n", 4);
}

void shift_up_rb(t_stack *stack)
{
    shift_up(stack);
    write(1, "rb\n", 3);
}
