/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:53:04 by marvin            #+#    #+#             */
/*   Updated: 2023/04/17 15:56:26 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->len = 0;
}

void	remove_list(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*prev;

	if (!stack->first)
		return ;
	node = stack->first;
	prev = NULL;
	while (node && node->data != value)
	{
		prev = node;
		node = node->next;
	}
	if (!node)
		return ;
	if (node == stack->first)
		stack->first = node->next;
	else if (node == stack->last)
	{
		stack->last = prev;
		prev->next = NULL;
	}
	else
		prev->next = node->next;
	free(node);
}

void	insert_up(t_stack *stack, int num)
{
	t_node	*new;

	new = create_node(num);
	if (!new)
		return ;
	if (stack->first == NULL)
		stack->last = new;
	new->next = stack->first;
	stack->first = new;
}

void	add_node(t_stack *stack, t_node *new)
{
	if (stack->first == NULL)
	{
		stack->first = new;
		stack->last = new;
	}
	else
	{
		stack->last->next = new;
		stack->last = new;
	}
}

t_node	*create_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->index = 0;
		new->data = num;
		new->next = NULL;
	}
	else
		write(1, "Error\n", 7);
	return (new);
}
