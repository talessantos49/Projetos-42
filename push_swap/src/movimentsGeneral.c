/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentsGeneral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:45:06 by marvin            #+#    #+#             */
/*   Updated: 2023/04/11 02:45:36 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift_up(t_stack *stack)
{
	t_node	*aux;
	t_node	*new;

	aux = malloc(sizeof(t_node));
	new = malloc(sizeof(t_node));
	if (new)
	{
		new->data = stack->first->data;
		new->next = NULL;
		unstack(stack);
		if (stack->first == NULL)
			stack->first = new;
		else
		{
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

void	shift_up_rr(t_stack *stackA, t_stack *stackB)
{
	shift_up(stackA);
	shift_up(stackB);
	write(1, "rr\n", 3);
}

void	swap_ss(t_stack *stackA, t_stack *stackB)
{
	t_node	*aux1;
	t_node	*aux2;

	aux1 = NULL;
	aux2 = NULL;
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

void	shift_down_rrr(t_stack *stackA, t_stack *stackB)
{
	int	aux;
	int	aux2;

	aux = last_number(stackA)->data;
	remove_list(stackA, aux);
	insert_down(stackA, aux);
	aux2 = last_number(stackB)->data;
	remove_list(stackB, aux2);
	insert_down(stackB, aux2);
	write(1, "rrr\n", 4);
}

void	stack_up(t_stack *stack, int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->data = value;
		new->next = stack->first;
		stack->first = new;
		stack->len++;
	}
	else
		write(1, "Error\n", 7);
}
