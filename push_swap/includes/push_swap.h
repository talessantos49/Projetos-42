/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:50:08 by tasantos          #+#    #+#             */
/*   Updated: 2023/04/22 15:34:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../includes/libft.h"

typedef struct s_node{
	int				data;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack{
	t_node	*first;
	t_node	*last;
	int		len;
	int		size;
	int		bit_size;
	int		list_size;	
}	t_stack;

long long int	ft_atoi_push(const char	*str);
int				check_ordenated(int argc, char *argv[]);
int				check_max_min(char *str);
int				check_numbers(char *str);
int				duplicated_args(int argc, char *argv[]);
void			checkers(int argc, char *argv[]);
void			push_a(t_stack *stackA, t_stack *stackB);
void			swap_a(t_stack *stackA);
void			shift_down_rra(t_stack *stack);
void			shift_up_ra(t_stack *stack);
void			push_b(t_stack *stackA, t_stack *stackB);
void			swap_b(t_stack *stackB);
void			shift_down_rrb(t_stack *stack);
void			shift_up_rb(t_stack *stack);
void			shift_up(t_stack *stack);
void			shift_up_rr(t_stack *stackA, t_stack *stackB);
void			swap_ss(t_stack *stackA, t_stack *stackB);
void			shift_down_rrr(t_stack *stackA, t_stack *stackB);
void			create_stack(t_stack *stack);
void			remove_list(t_stack *stack, int valor);
void			stack_up(t_stack *stack, t_node *aux);
void			insert_up(t_stack *stack, int num);
t_node			*unstack(t_stack *stack);
t_node			*last_node(t_stack *stack);
int				last_number(t_stack *stack);
void			sort_two(t_stack *stackA);
void			sort_three(t_stack *stackA);
void			sort_four(t_stack *stackA, t_stack *stackB);
void			sort_five(t_stack *stackA, t_stack *stackB);
void			push_three(t_stack *stackA, t_stack *stackB);
void			insert_down(t_stack *stack, int num);
void			remove_last(t_stack *stack, int valor);
void			sort_four_last(t_stack *stacka, t_stack *stackb);
void			double_rra(t_stack *stacka);
void			swap_push(t_stack *stacka, t_stack *stackb);
void			sort_three_last(t_stack* stacka);
void			free_node(t_node *node);
void			free_stack(t_stack *stacka);
void			free_all(t_stack *stacka, t_stack *stackb);
t_node			*create_node(int num);
void			add_node(t_stack *stack, t_node *new);
void			initial_stack(t_stack *stacka, int argc, char *argv[]);
void			imprimir_pilha(t_stack *stacka, char a_or_b);
//quicksort
int				bigest_number(t_stack *stack);
int				lowest_number(t_stack *stack);
void			quick_sort(t_stack *stacka, t_stack *stackb);
void			pivot(t_stack *stacka, t_stack *stackb);
int				stack_len(t_stack *stack);
void			quick_insert(t_stack *stacka,t_stack *stackb);
//perform
int				index_nodes(t_stack *stack);
void			core_ordenation(t_stack *stacka, t_stack *stackb);
void			indexando(t_node *stack);

#endif
