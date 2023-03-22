/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:41:44 by marvin            #+#    #+#             */
/*   Updated: 2023/03/20 15:41:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_two(t_stack *stackA)
{
    if (stackA->first->data < stackA->last->data)
        swap_a(stackA);
}

void sort_three(t_stack *stackA)
{
    ft_printf("first [%d]\nlast [%d]\nnext [%d]\n", stackA->first->data, stackA->last->data, stackA->first->next->data);
    if (stackA->first->data < stackA->first->next->data)
        swap_a(stackA);
    if (stackA->first->next->data < stackA->first->data)
        shift_down_rra(stackA);
    if (stackA->last->data < stackA->first->next->data)
        shift_up_ra(stackA);
}