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
	int tam;
} t_stack;


long long int	ft_atoi_push(const char	*str);
int	            check_max_min(char *str);
int	            check_numbers(char *str);
int             duplicated_args(int argc, char *argv[]);
void	        checkers(int argc, char *argv[]);

#endif


