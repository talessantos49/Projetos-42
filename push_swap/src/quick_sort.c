/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/19 21:28:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void imprimir_pilha(t_stack *stacka)
{
	t_node *aux;
	
	aux = stacka->first;
    while(aux)
	{
		ft_printf("[%d]->", aux->data);
		aux = aux->next;
	}
    ft_printf("\n-----------------------------\n");
}

int	bigest_number(t_stack *stack)
{
	t_node	*aux;
	int		max;

	max = stack->first->data;
	aux = stack->first;
	while (aux->next)
	{
		if (max < aux->next->data)
			max = aux->next->data;
		aux = aux->next;
	}
	return (max);
}

int	lowest_number(t_stack *stack)
{
	t_node	*aux;
	int		min;

	if (!stack->first->next)
		return (0) ;
	min = stack->first->data;
	aux = stack->first;
	while (aux->next)
	{
		if (min > aux->next->data)
			min = aux->next->data;
		aux = aux->next;
	}
	return (min);
}

// int	index_nodes(t_stack *stack)
// {
// 	t_node	*aux;

// 	aux = stack->first;
// 	while (aux->next)
// 	{
// 		aux = aux->next;
// 		i++;
// 	}
// 	return (aux->data);
// }

// int	duo_ordenaded(t_stack *stack)
// {
// 	t_node *aux;
// 	int		pivot;

// 	aux = stack->first;
// 	pivot = aux->data;
// 	while (aux->next)
// 	{
// 		if (pivot > aux->next->data)
// 			push_b()
// 	}
// }

int	ordenaded(t_stack *stack)
{
	t_node	*aux;
	int		value;

	if (!stack->first)
		return (1);
	aux = stack->first;
	value = aux->data;
	while (aux->next)
	{
		if (value < aux->next->data)
			value = aux->next->data;
		else
			return (0);
		aux= aux->next;
	}
	return (1);
}

int	invert_ordenaded(t_stack *stack)
{
	t_node	*aux;
	int		value;

	if (!stack->first)
		return (1);
	aux = stack->first;
	value = aux->data;
	while (aux->next)
	{
		if (value > aux->next->data)
		{
			// ft_printf("value : [%d]\naux->next->data : [%d]\n", value, aux->next->data);
			value = aux->next->data;
		}
		else
		{
			// ft_printf("value : [%d]\naux->next->data : [%d]\n", value, aux->next->data);
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}

// t_node	pivot(t_stack *stacka, t_stack *stackb)
void	pivot(t_stack *stacka, t_stack *stackb)
{
	t_node	*aux;
	int		pivot_number;

	aux = stacka->first;
	if (ordenaded(stacka))
	{
		push_a(stacka, stackb);
		shift_up_ra(stacka);
		// ft_printf("Entrou ordenado!\n");
		// pivot(stacka, stackb);
		return ;
		// break;
	}
	// else 
	// 	shift_down_rra(stacka);
	if (aux->data > lowest_number(stacka) && aux->data < bigest_number(stacka))
		pivot_number = aux->data;
	else
	{
		swap_a(stacka);
		pivot_number = aux->data;
	}
	// ft_printf("Pivot: [%d]\n", pivot_number);
	while (aux)
	{
		// ft_printf("Aux->data : [%d]\n", aux->next->data);
		if (pivot_number < aux->next->data)
		{
			swap_a(stacka);
			push_b(stacka, stackb);
			// ft_printf("\tSTACK - A\n");
			// imprimir_pilha(stacka);
			// ft_printf("\tSTACK - B\n");
			// imprimir_pilha(stackb);
		}
		else if (pivot_number == aux->data)
		{
			// ft_printf("\tSTACK - A\n");
			// imprimir_pilha(stacka);
			// ft_printf("\tSTACK - B\n");
			// imprimir_pilha(stackb);
			break;
		}
		// else if (pivot != aux->data)
		else
		{
			// ft_printf("\tSTACK - A\n");
			// imprimir_pilha(stacka);
			// ft_printf("\tSTACK - B\n");
			// imprimir_pilha(stackb);
			shift_up_ra(stacka);
		}
		aux = aux->next;
	}
	// ft_printf("\tEntrando no Pivo\n-----------------------------------\n");
	// ft_printf("\tSTACK - A\n");
	// imprimir_pilha(stacka);
	// ft_printf("\tSTACK - B\n");
	// imprimir_pilha(stackb);
	// ft_printf("\tSaindo do Pivo\n-----------------------------------\n\n");
	// push_a(stacka, stackb);
	// push_b(stacka, stackb);
	pivot(stacka, stackb);
	// ft_printf("Cheguei Aqui\n");
	// while (stackb->first)
	// 	push_a(stacka, stackb);
	// return (pivot);
	return ;
}

void	quick_insert(t_stack *stacka,t_stack *stackb)
{
	t_node	*aux;
	int	low_number;

	low_number = lowest_number(stackb);
	aux = stackb->first;
	while (aux)
	{
		if (low_number == aux->data)
		{
			// ft_printf("\naux->data: [%d]\naux->next->data: [%d]\n", aux->data, aux->next->data);
			push_a(stacka, stackb);
			shift_up_ra(stacka);
		}
		else
			shift_up_rb(stackb);
		// imprimir_pilha(stacka);
		// imprimir_pilha(stackb);
		low_number = lowest_number(stackb);
		aux = aux->next;
	}
	push_a(stacka, stackb);
	shift_up_ra(stacka);
}

void	quick_sort(t_stack *stacka, t_stack *stackb)
{
	// if (invert_ordenaded(stacka))
	// {
	// 	ft_printf("Inverted_ordenaded!\n");
	// 	imprimir_pilha(stacka);
	// // }
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	pivot(stacka, stackb);
	// // pivot(stacka, stackb);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	// pivot(stacka, stackb);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	quick_insert(stacka, stackb);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	// // pivot(stacka, stackb);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	// shift_down_rra(stacka);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	// pivot(stacka, stackb);
	// imprimir_pilha(stacka);
	// imprimir_pilha(stackb);
	// if (ordenaded(stacka))
	// {
	// 	ft_printf("Ordenaded!\n");
	// 	imprimir_pilha(stacka);
	// }
	// if (invert_ordenaded(stacka))
	// {
	// 	ft_printf("Inverted_ordenaded!\n");
	// 	imprimir_pilha(stacka);
	// }
	// if (ordenaded(stackb))
	// {
	// 	ft_printf("Ordenaded!\n");
	// 	imprimir_pilha(stackb);
	// }
	// if (invert_ordenaded(stackb))
		// imprimir_pilha(stackb);
}
