/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/24 11:49:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack->first;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

void	set_index(t_node *stack)
{
	t_node	*stack_aux;
	t_node	*stack_copy;

	stack_copy = stack;
	while (stack)
	{
		stack_aux = stack_copy;
		while (stack_aux)
		{
			if (stack->data > stack_aux->data)
				(stack->index)++;
			stack_aux = stack_aux->next;
		}
		stack = stack->next;
	}
}

int	get_max_bit(int arg)
{
	int	max_bits;

	max_bits = 0;
	while (arg != 0)
	{
		max_bits++;
		arg = arg >> 1;
	}
	return (max_bits);
}

void	radix(int arg, t_stack *stacka, t_stack *stackb)
{
	int	i;
	int	max_bit;
	int	arg_aux;

	max_bit = get_max_bit(arg - 1);
	i = 0;
	while (i < max_bit)
	{
		arg_aux = arg;
		while (arg_aux > 0)
		{
			if ((stacka->first->index >> i & 1))
				shift_up_ra(stacka);
			else
				push_b(stacka, stackb);
			arg_aux--;
		}
		while (stackb->first)
			push_a(stacka, stackb);
		i++;
	}
}
