/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:53:04 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 10:53:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void create_stack(t_stack *stack){
	stack->first = NULL;
    stack->last = NULL;
	stack->len = 0;
}

void remove_list(t_stack *stack, int valor){
	t_node *outset = stack->first;
	t_node *node_remove = NULL;

	if (outset != NULL && stack->first->data == valor){
		node_remove = stack->first;
		stack->first = node_remove->next;
		if(stack->first == NULL)
			stack->last = NULL;
	}
	else {
		while (outset != NULL && outset->next != NULL && outset->next->data != valor){
			outset = outset->next;
		}
		if (outset != NULL && outset->next != NULL){
			node_remove = outset->next;
			outset->next = node_remove->next;
			if (outset->next == NULL)
				stack->last = outset;
		}
	}
	if (node_remove){
		free(node_remove);
		stack->len--;
	}
}

void stack_up(t_stack *stack, int value)
{
	t_node *new = malloc(sizeof(t_node));
	if(new){
		new->data = value;
		new->next = stack->first;
		stack->first = new;
		stack->len++;
	}
	else
		write(1, "Error\n", 7);
}

void insert_up(t_stack *stack, int num)
{
    t_node *new = malloc(sizeof(t_node));

    if(new){
        new->data = num;
		if (stack->first == NULL){
			new->next = NULL;
			stack->first = new;
			stack->last = new;
		}
		else {
			new->next = stack->first;
			stack->first = new;
		}
        stack->len++;
    }
    else
		write(1, "Error\n", 7);
}

t_node *unstack(t_stack *stack){
	if (stack->first){
		t_node *remove = stack->first;
		stack->first = remove->next;
		stack->len--;
		return remove;
	}
	return NULL;
}
