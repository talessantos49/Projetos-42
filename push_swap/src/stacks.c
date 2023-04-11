/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:53:04 by marvin            #+#    #+#             */
/*   Updated: 2023/04/11 02:53:49 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_stack(t_stack *stack)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->len = 0;
}

void	remove_list(t_stack *stack, int valor)
{
	t_node	*outset;
	t_node	*node_remove;

	outset = stack->first;
	node_remove = NULL;
	if (outset != NULL && stack->first->data == valor)
	{
		node_remove = stack->first;
		stack->first = node_remove->next;
		if (stack->first == NULL)
			stack->last = NULL;
	}
	else
	{
		while (outset != NULL && outset->next != NULL
			&& outset->next->data != valor)
			outset = outset->next;
		if (outset != NULL && outset->next != NULL)
		{
			node_remove = outset->next;
			outset->next = node_remove->next;
			if (outset->next == NULL)
				stack->last = outset;
		}
	}
	if (node_remove)
	{
		free(node_remove);
		stack->len--;
	}
}

void	insert_up(t_stack *stack, int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->data = num;
		if (stack->first == NULL)
		{
			new->next = NULL;
			stack->first = new;
			stack->last = new;
		}
		else
		{
			new->next = stack->first->next;
			stack->first = new;
		}
		stack->len++;
	}
	else
		write(1, "Error\n", 7);
}

void	insert_down(t_stack *stack, int num)
{
	t_node	*new;
	t_node	*aux;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->data = num;
		if (stack->first == NULL)
		{
			new->next = NULL;
			stack->first = new;
			stack->last = new;
		}
		else
		{
			aux = stack->first;
			while (aux->next)
				aux = aux->next;
			aux->next = new;
			stack->last = new;
		}
		stack->len++;
	}
	else
		write(1, "Error\n", 7);
}

t_node	*unstack(t_stack *stack)
{
	t_node	*remove;

	if (stack->first)
	{
		remove = stack->first;
		stack->first = remove->next;
		stack->len--;
		return (remove);
	}
	return (NULL);
}
