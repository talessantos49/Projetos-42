/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:50:08 by tasantos          #+#    #+#             */
/*   Updated: 2023/02/13 20:52:00 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../includes/libft.h"

typedef struct s_node{
	int data;
	struct s_node *next;
	struct s_node *prev;
}t_node;

typedef struct s_stack{
	t_node *first;
    t_node *last;
	int len;
} t_stack;

long long int	ft_atoi_push(const char	*str);
int             check_ordenated(int argc, char *argv[]);
int	            check_max_min(char *str);
int	            check_numbers(char *str);
int             duplicated_args(int argc, char *argv[]);
void	        checkers(int argc, char *argv[]);
void            push_a(t_stack *stackA, t_stack *stackB);
void            swap_a(t_stack *stackA);
void            shift_down_rra(t_stack *stack);
void            shift_up_ra(t_stack *stack);
void            push_b(t_stack *stackA, t_stack *stackB);
void            swap_b(t_stack *stackB);
void            shift_down_rrb(t_stack *stack);
void            shift_up_rb(t_stack *stack);
void            shift_up(t_stack *stack);
void            shift_up_rr(t_stack *stackA, t_stack *stackB);
void            swap_ss(t_stack *stackA, t_stack *stackB);
void            shift_down_rrr(t_stack *stackA, t_stack *stackB);
void            create_stack(t_stack *stack);
void            remove_list(t_stack *stack, int valor);
void            stack_up(t_stack *stack, int value);
void            insert_up(t_stack *stack, int num);
t_node          *unstack(t_stack *stack);
void            sort_two(t_stack *stackA);
void            sort_three(t_stack *stackA);
void			sort_four(t_stack *stackA, t_stack *stackB);
void			sort_five(t_stack *stackA, t_stack *stackB);
void			push_three(t_stack *stackA, t_stack *stackB);
void			insert_down(t_stack *stack, int num);
void			remove_last(t_stack *stack, int valor);
void imprimir_pilha(t_stack *stack, char c);

#endif
