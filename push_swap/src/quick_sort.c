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
	ft_printf("\n");
	aux = stacka->first;
	if (a_or_b == 'a')
		ft_printf("A->");
	else
		ft_printf("B->");
	while (aux)
	{
		ft_printf("[%d]->",aux->index);
		aux = aux->next;
	}
    ft_printf("\n-----------------------------\n");
}

int	bigest_number(t_stack *stack)
{
	t_node	*aux;
	int		max;

	if (!stack->first)
		return (0);
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

int	bigest_number_index(t_stack *stack)
{
	t_node	*aux;
	int		max;

	if (!stack->first)
		return (0);
	max = stack->first->index;
	aux = stack->first;
	while (aux->next)
	{
		if (max < aux->next->index)
			max = aux->next->index;
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

// int	*general_bigest_number(t_stack *stack, int bigest)
// {
// 	t_node	*aux;
// 	int		max;
// 	int		*array;

// 	if (!stack->first)
// 		return (0);
// 	max = lowest_number(stack);
// 	aux = stack->first;
// 	while (aux->next)
// 	{
// 		if (max < aux->data)
// 			if (bigest != aux->data)
// 				max = aux->data;
// 		aux = aux->next;
// 	}
// 	return (array);
// }

int	*lowest_ten(t_stack *stack)
{
	t_node	*aux;
	int		min;
	int		i;
	int		*array;
	int		divisor;

	if (!stack->first->next)
		return (0) ;
	array = calloc(sizeof(int), 10);
	i = 0;
	divisor = 0;
	if (stack_len(stack) <= 100)
		divisor = 5;
	else
		divisor = 10;
	while (i < divisor)
	{
		// min = INT_MAX;
		min = lowest_number(stack);
		// min = bigest_number(stack);
		aux = stack->first;
		while (aux->next)
		{
			// if (min > aux->data)
			if (min < aux->data)
				if (array[i-1] > aux->data)
					min = aux->data;
			aux = aux->next;
		}
		array[i] = min;
		i++;
	}
	return (array);
}

// int	*lowest_ten(t_stack *stack)
// {
// 	t_node	*aux;
// 	int		min;
// 	int		*array;
// 	int		i;

// 	i = 0;
// 	array = calloc(sizeof(int), 10);
// 	if (!stack->first->next)
// 		return (0) ;
// 	min = stack->first->data;
// 	aux = stack->first;
// 	array[i] = min;
// 	while (aux->next)
// 	{
// 		if (min > aux->next->data)
// 			min = aux->next->data;
// 		aux = aux->next;
// 		array[i] = min;
// 		i++;
// 	}
// 	return (array);
// }

// void copy_lowest_ten(t_stack *stack, int *array, int min, int count)
// {
//     if (!stack->first)
//         return;
//     if (count == 10)
//         return;
//     if (stack->first->data < min || count == 0)
//     {
//         min = stack->first->data;
//         array[count] = min;
//         copy_lowest_ten(stack, array, min, count + 1);
//     }
//     else
//     {
//         copy_lowest_ten(stack, array, min, count);
//     }
//     return;
// }

// void copy_lowest_ten(t_stack *stack, int *array, int count)
// {
//     if (!stack || !stack->first || count >= 10)
//         return;
    
//     int min = stack->first->data;
//     t_node *aux = stack->first;
    
//     while (aux)
//     {
//         if (aux->data < min)
//             min = aux->data;
//         aux = aux->next;
//     }
    
//     aux = stack->first;
//     while (aux && count < 10)
//     {
//         if (aux->data == min)
//         {
//             array[count] = min;
//             count++;
//         }
//         aux = aux->next;
//     }
    
//     return;
// }

// int *lowest_ten(t_stack *stack)
// {
//     int *array = calloc(sizeof(int), 10);
//     if (!array)
//         return (NULL);
//     copy_lowest_ten(stack, array, 0);
//     return array;
// }

// int is_empty(t_stack *stack) {
//     return stack->first == NULL;
// }

// int *stack_to_array(t_stack *stack)
// {
//     int *arr = malloc(stack->size * sizeof(int));
//     if (!arr)
//         return NULL;
    
//     t_node *node = stack->first;
//     for (int i = 0; i < stack->size; i++) {
//         arr[i] = node->data;
//         node = node->next;
//     }

//     return arr;
// }

// int *lowest_ten(t_stack *stack)
// {
//     t_stack temp_stack;
//     int *array = calloc(10, sizeof(int));

//     while (stack->size > 10)
//     {
//         init_stack(&temp_stack);
//         while (!is_empty(stack))
//         {
//             if (stack->size <= (temp_stack.size + stack->size) / 2)
//                 push_b(stack, &temp_stack);
//             else
//                 rotate_a(stack);
//         }
//         while (!is_empty(&temp_stack))
//             push_a(stack, &temp_stack);
//     }
//     stack_to_array(stack);
//     return array;
// }

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

int	inverted_index_nodes(t_stack *stack)
{
	t_node	*aux;
	int		big_number;
	int		position_number;

	big_number = bigest_number(stack);
	aux = stack->first;
	position_number = 0;
	while (aux->next)
	{
		if (aux->data == big_number)
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

int	anti_ordenaded(t_stack *stack)
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
		{
			imprimir_pilha(stack, 'a');
			ft_printf("valor:[%d]\n", aux->data);
			value = aux->next->data;
		}
		else
		{
			ft_printf("valor:[%d]\n", aux->data);
			return (0);
		}
		aux= aux->next;
	}
	ft_printf("Estou ordenado!\n\n");
	imprimir_pilha(stack, 'a');
	exit(1);
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

void	push_rotate(t_stack *stacka, t_stack *stackb)
{
	t_node	*auxiliar;
	int		low_number;
	int		position_number;
	int		len_stack;

	push_a(stacka, stackb);
	
	low_number = lowest_number(stackb);
	position_number = index_nodes(stackb);
	len_stack = stack_len(stackb);
	auxiliar = stackb->first;
	if (auxiliar->data == low_number)
		shift_up_ra(stacka);
	else if (position_number > (len_stack /2))
		shift_up_rr(stacka, stackb);
	else
	{
		shift_up_ra(stacka);
		shift_down_rrb(stackb);
	}
}

// void	rotate_direction(t_stack *stack)
// {
// 	int	position_number;
// 	int	index_position;

// 	position_number = index_nodes(stack);
// 	index_position = stack_len(stack);
// 	if (position_number > (index_position / 2))
// 		shift_down_rrb(stack);
// 	else
// 		shift_up_rb(stack);
// }

void	rotate_direction(t_stack *stack)
{
	int	position_number;
	int	index_position;

	position_number = index_nodes(stack);
	index_position = stack_len(stack);
	if (position_number > (index_position / 2))
		shift_down_rra(stack);
	else
		shift_up_ra(stack);
}

void	inverted_rotate_direction(t_stack *stack)
{
	int	position_number;
	int	len_stack;

	position_number = inverted_index_nodes(stack);
	len_stack = stack_len(stack);
	if (position_number > (len_stack / 2))
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
			push_rotate(stacka, stackb);
			// push_a(stacka, stackb);
			// shift_up_ra(stacka);
		}
		else
			rotate_direction(stackb);
		auxiliar = stackb->first;
		if (auxiliar->next == NULL)
			break;
	}
}

void inverted_core_ordenation(t_stack *stacka, t_stack *stackb)
{
	t_node	*auxiliar;
	int		big_number;

	auxiliar = stackb->first;
	while (auxiliar)
	{
		big_number = bigest_number(stackb);
		if (big_number == auxiliar->data)
		{
			// push_rotate(stacka, stackb);
			push_a(stacka, stackb);
			// shift_up_ra(stacka);
		}
		else
			inverted_rotate_direction(stackb);
		auxiliar = stackb->first;
		if (auxiliar->next == NULL)
			break;
	}
}

// int		number_pivot(t_stack *stacka, t_stack *stackb)
// {
// 	int	pivot_number;

// 	pivot_number = 0;
// 	if (stack_len(stacka) <= 2 && stacka->first->next != NULL)
// 	{
// 		push_b(stacka, stackb);
// 		pivot_number = stacka->first->data;
// 	}
// 	else if (stacka->last->data != lowest_number(stacka) && stacka->last->data != bigest_number(stacka))
// 	{
// 		shift_down_rra(stacka);
// 		pivot_number = stacka->first->data;
// 		shift_up_ra(stacka);
// 	}
// 	else if (stacka->first->data != lowest_number(stacka) && stacka->first->data != bigest_number(stacka))
// 	{
// 		pivot_number = stacka->first->data;
// 		shift_up_ra(stacka);
// 	}
// 	return (pivot_number);
// }

int		number_pivot(t_stack *stacka)
{
	t_node	*aux;
	int	mid;

	mid = bigest_number_index(stacka)/2;
	aux = stacka->first;
	if (mid <= 2)
		return (aux->data);
	while (aux)
	{
		if (aux->index == mid)
			return (aux->data);
		aux = aux->next;
	}
	return (0);
}

void	choice_pivot(t_stack *stacka, t_stack *stackb)
{
	t_node	*aux;
	int		pivot_number;

	aux = stacka->first->next;
	pivot_number = number_pivot(stacka);
	// pivot_number = number_pivot(stacka, stackb);
	if (!aux)
		return;
	while (aux)
	{
		if (invert_ordenaded(stackb))
			if (stacka->first->next == NULL)
				return ;
		if (stacka->first->next != NULL)
		{
			if (stacka->first->data == pivot_number)
			{
				pivot_number = number_pivot(stacka);
				// pivot_number = number_pivot(stacka, stackb);
				break ;
			}
			else if (stacka->first->data > pivot_number)
				push_b(stacka, stackb);
			else if (stacka->first->data < pivot_number)
				shift_up_ra(stacka);
			if (stacka->first->next == NULL)
				return ;
			if (stackb->first != NULL)
				if (stackb->first->data == pivot_number)
					break;
		}
		else
		{
			push_b(stacka, stackb);
			break; ;
		}
		aux = aux->next;
	}
	choice_pivot(stacka, stackb);
	push_b(stacka, stackb);
	return ;
}

void	returned_a (t_stack *stacka, t_stack *stackb)
{
	t_node	*auxiliar;

	auxiliar = stackb->first->next;
	// ft_printf("Estou aqui!\n");
	while (auxiliar)
	{
		push_a(stacka, stackb);
		auxiliar = auxiliar->next;
	}
	push_a(stacka, stackb);
	// return ;
	exit(1);
}

void pivot(t_stack *stacka, t_stack *stackb)
{
    t_node  *aux;
    t_node  *aux_temp;
    int     pivot_number;

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
			break;
		else
			shift_up_ra(stacka);
		if (aux_temp == NULL)
			break;
		else
			aux = aux_temp;
	}
	pivot(stacka, stackb);
	return ;
}

void	quick_insert(t_stack *stacka,t_stack *stackb)
{
	t_node	*aux;
	int	big_number;

	big_number = bigest_number(stackb);
	aux = stackb->first->next;
	while (aux)
	{
		if (big_number == aux->data)
			push_a(stacka, stackb);
		else
			inverted_core_ordenation(stacka, stackb);
		big_number = bigest_number(stackb);
		if (aux == NULL)
			break ;
		else if (stackb->first->next == NULL)
			break ;
		else
			aux = aux->next;
	}
	push_a(stacka, stackb);
}


//pivot funcional com 100% porém muitos movimentos.
// void pivot(t_stack *stacka, t_stack *stackb)
// {
//     t_node  *aux;
//     t_node  *aux_temp;
//     int     pivot_number;

//     pivot_number = 0;
//     aux = stacka->first->next;
//     aux_temp = aux;
// 	if (ordenaded(stacka))
// 		return ;
// 	if (stacka->first->data > lowest_number(stacka) && stacka->first->data < bigest_number(stacka))
// 		pivot_number = stacka->first->data;
// 	else
//     {
// 		swap_a(stacka);
//         pivot_number = stacka->first->data;
//     }
// 	while (1)
// 	{
// 		if (ordenaded(stacka))
// 		{
// 			if (stackb->first != NULL)
// 				core_ordenation(stacka, stackb);
// 			break;
// 		}
// 		if (aux->next != NULL)
// 			aux_temp = aux->next;
// 		if (pivot_number < aux->data)
// 		{
// 			swap_a(stacka);
// 			push_b(stacka, stackb);
// 		}
// 		else if (pivot_number == aux->data)
// 			break;
// 		else
// 			shift_up_ra(stacka);
// 		if (aux_temp == NULL)
// 			break;
// 		else
// 			aux = aux_temp;
// 	}
// 	pivot(stacka, stackb);
// 	return ;
// }

// void	quick_insert(t_stack *stacka,t_stack *stackb)
// {
// 	t_node	*aux;
// 	int	low_number;

// 	low_number = lowest_number(stackb);
// 	aux = stackb->first->next;
// 	while (aux)
// 	{
// 		if (low_number == aux->data)
// 		{
// 			push_rotate(stacka, stackb);
// 			// push_a(stacka, stackb);
// 			// shift_up_ra(stacka);
// 		}
// 		else
// 			core_ordenation(stacka, stackb);
// 			// shift_up_rb(stackb);
// 		low_number = lowest_number(stackb);
// 		aux = aux->next;
// 	}
// 	push_a(stacka, stackb);
// 	shift_up_ra(stacka);
// }

// static void	set_index(t_stack *stack_a)
// {
// 	t_stack	*stack_copy;
// 	t_stack	*stack_aux;

// 	stack_copy = stack_a;
// 	while (stack_a)
// 	{
// 		stack_aux = stack_copy;
// 		while (stack_aux)
// 		{
// 			if (stack_a->number > stack_aux->number)
// 				(stack_a->index)++;
// 			stack_aux = stack_aux->next;
// 		}
// 		stack_a = stack_a->next;
// 	}
// }

void	indexando(t_node *stack)
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

void print_first_ten(int *array) {
    int i = 0;
    while (i < 5) {
        ft_printf("%d ", array[i]);
        i++;
    }
    ft_printf("\n");
}

void	quick_sort(t_stack *stacka, t_stack *stackb)
{
	// // indexando(stacka->first);
	// ft_printf("Biggest[%d]\n", bigest_number_index(stacka));
	// ft_printf("index->last [%d]\n", stacka->last->index);
	// push_b(stacka, stackb);
	
	choice_pivot(stacka, stackb);
	quick_insert(stacka, stackb);
	// pivot(stacka, stackb);
}
