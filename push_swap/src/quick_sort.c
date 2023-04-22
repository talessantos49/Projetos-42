/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/22 15:57:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void imprimir_pilha(t_stack *stacka, char a_or_b)
{
	t_node *aux;
	
	aux = stacka->first;
	if (a_or_b == 'a')
		ft_printf("A->");
	else
		ft_printf("B->");
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

int	index_nodes(t_stack *stack)
{
	t_node	*aux;
	int		low_number;
	int		position_number;

	low_number = lowest_number(stack);
	aux = stack->first;
	position_number = 0;
	while (aux->next)
	{
		if (aux->data == low_number)
			break;
		position_number++;
		aux = aux->next;
	}
	return (position_number);
}

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

int	stack_len(t_stack *stack)
{
	t_node	*aux;
	int	i;

	i = 0;
	aux = stack->first;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

// void	pivot(t_stack *stacka, t_stack *stackb)
// {
// 	t_node	*aux;
// 	t_node	*aux_temp;
// 	int		pivot_number;
// 	// int		len;

// 	pivot_number = 0;
// 	aux = stacka->first;
// 	aux_temp = aux;
// 	// len = stack_len(stacka);
// 	// aux1 = malloc(sizeof(t_node));
// 	if (ordenaded(stacka))
// 	{
// 		push_a(stacka, stackb);
// 		shift_up_ra(stacka);
// 		// ft_printf("Entrou ordenado!\n");
// 		// pivot(stacka, stackb);
// 		return ;
// 	}
// 	// else 
// 	// 	shift_down_rra(stacka);
// 	if (aux->data > lowest_number(stacka) && aux->data < bigest_number(stacka))
// 		pivot_number = aux->data;
// 	else
// 	{
// 		swap_a(stacka);
// 		pivot_number = aux->data;
// 	}
// 	while (1)
// 	{
// 		if (!(aux->next == NULL))
// 			aux_temp = aux->next;
// 		if (aux == NULL)
// 			break;
// 		if (pivot_number < aux->next->data)
// 		{
// 			swap_a(stacka);
// 			push_b(stacka, stackb);
// 		}
// 		else if (pivot_number == aux->data)
// 		{
// 			// ft_printf("Quebrou aqui!!");
// 			break;
// 		}
// 		else
// 			shift_up_ra(stacka);
// 		if (aux_temp == NULL)
// 			break;
// 		else
// 			aux = aux_temp;
// 	}
// 	// free(aux1);
// 	// ft_printf("\n\n\nFora do While ---fim\n\n");
// 	return ;
// }
void	rotate_direction(t_stack *stack)
{
	int	position_number;
	int	index_position;

	position_number = index_nodes(stack);
	index_position = stack_len(stack);
	if (position_number > (index_position / 2))
		shift_down_rrb(stack);
	else
		shift_up_rb(stack);
}

void core_ordenation(t_stack *stacka, t_stack *stackb)
{
	t_node	*auxiliar;
	int		low_number;

	auxiliar = stackb->first;
	while (auxiliar)
	{
		low_number = lowest_number(stackb);
		if (low_number == auxiliar->data)
		{
			push_a(stacka, stackb);
			shift_up_ra(stacka);
		}
		else
			rotate_direction(stackb);
		auxiliar = stackb->first;
		if (auxiliar->next == NULL)
			break;
	}
}

void pivot(t_stack *stacka, t_stack *stackb)
{
    t_node  *aux;
    t_node  *aux_temp;
	t_node	*auxer;
	t_node	*auxiliar;
    int     pivot_number;
	int		low_number;
	int		big_number;

    pivot_number = 0;
    aux = stacka->first->next;
    aux_temp = aux;
	if (ordenaded(stacka))
		return ;
	if (stacka->first->data > lowest_number(stacka) && stacka->first->data < bigest_number(stacka))
		pivot_number = stacka->first->data;
	else
    {
		swap_a(stacka);
        pivot_number = stacka->first->data;
    }
	while (1)
	{
		if (ordenaded(stacka))
		{
			if (stackb->first != NULL)
				core_ordenation(stacka, stackb);
			break;
		}
		if (aux->next != NULL)
			aux_temp = aux->next;
		if (pivot_number < aux->data)
		{
			swap_a(stacka);
			push_b(stacka, stackb);
		}
		else if (pivot_number == aux->data)
		{
			break;
		}
		else
			shift_up_ra(stacka);
		if (aux_temp == NULL)
			break;
		else
			aux = aux_temp;
	}
	pivot(stacka, stackb);
	low_number = lowest_number(stacka);
	auxer = stacka->first;
	while (!(ordenaded(stacka)))
	{
		if (auxer->data == low_number)
			shift_up_ra(stacka);
		else if (auxer->next->data < auxer->data)
		{
			swap_a(stacka);
			shift_up_ra(stacka);
		}
		else
			shift_up_ra(stacka);
		auxer = stacka->first->next;
	}
	auxiliar = stackb->first;
	while (auxiliar)
	{
		big_number = lowest_number(stackb);
		if (big_number == auxiliar->data)
		{
			push_a(stacka, stackb);
			shift_up_ra(stacka);
		}
		else 
			shift_up_rb(stackb);
		auxiliar = stackb->first;
		if (auxiliar->next == NULL)
			break;
	}
	return ;
}

void	quick_insert(t_stack *stacka,t_stack *stackb)
{
	t_node	*aux;
	int	low_number;

	low_number = lowest_number(stackb);
	aux = stackb->first->next;
	while (aux)
	{
		if (low_number == aux->data)
		{
			push_a(stacka, stackb);
			shift_up_ra(stacka);
		}
		else
			shift_up_rb(stackb);
		low_number = lowest_number(stackb);
		aux = aux->next;
	}
	push_a(stacka, stackb);
	shift_up_ra(stacka);
}

void	quick_sort(t_stack *stacka, t_stack *stackb)
{
	pivot(stacka, stackb);
	quick_insert(stacka, stackb);
}
