/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsGeneral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:45:06 by marvin            #+#    #+#             */
/*   Updated: 2023/03/22 10:45:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void shift_up(t_stack *stack)
{
	t_node *aux = malloc(sizeof(t_node));
	t_node *new = malloc(sizeof(t_node));

	if (new){
		new->data = stack->first->data;
		new->next = NULL;
		unstack(stack);
		if (stack->first == NULL)
			stack->first = new;
		else{
			aux = stack->first;
			while (aux->next)
				aux = aux->next;
			aux->next = new;
		}
		stack->len++;
	}
	else
		write(1, "Error\n", 7);
}

void shift_up_rr(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
    write(1, "rr\n", 3);
}

void swap_ss(t_stack *stackA, t_stack *stackB){
	t_node *aux1 = NULL;
	t_node *aux2 = NULL;

	aux1 = unstack(stackA);
	aux2 = unstack(stackA);
	stack_up(stackA, aux1->data);
	stack_up(stackA, aux2->data);

	aux1 = unstack(stackB);
	aux2 = unstack(stackB);
	stack_up(stackB, aux1->data);
	stack_up(stackB, aux2->data);
    write(1, "ss\n", 3);
}

void shift_down_rrr(t_stack *stackA, t_stack *stackB)
{	
    int aux;
    int aux2;

    aux = stackA->last->data;
    remove_list(stackA, stackA->last->data);
    insert_up(stackA, aux);

    aux2 = stackB->last->data;
    remove_list(stackB, stackB->last->data);
    insert_up(stackB, aux2);
    write(1, "rrr\n", 4);
}