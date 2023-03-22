/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:33:00 by tasantos          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:08 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_atoi_push(const char	*str)
{
    long int        i;
	long int        negative;
	long long int   num;

	i = 0;
	num = 0;
	negative = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * negative);
}

void initial_stack(t_stack *stackA, int argc, char *argv[])
{
    int i;
    long long int value;

    i = 1;
    value = 0;
    while (i < argc)
    {
        value = ft_atoi_push(argv[i]);
        ft_printf("Value [%d]\n", value);
        insert_up(stackA, value);
        i++;
    }
}

void imprimir_pilha(t_stack *stack, char c){
	ft_printf("\n-------------- PILHA - ");
	ft_printf("%c",c);
	ft_printf(" tam: %d----------------\n", stack->len);
	t_node *aux = stack->first;
	while (aux){
		ft_printf("%d\n",aux->data);
		aux = aux->next;
	}
	ft_printf("\n-------------- FIM DA PILHA ---------\n");
}

int    main(int argc, char **argv)
{
	t_stack stackA;
	t_stack stackB;

    if (argc < 2)
        return (0);
    checkers(argc, argv);
	create_stack(&stackA);
    initial_stack(&stackA, argc, argv);
    imprimir_pilha(&stackA, 'A');
    if (argc == 3)
        sort_two(&stackA);
    if (argc == 4)
        sort_three(&stackA);
    imprimir_pilha(&stackA, 'A');
	create_stack(&stackB);

    return (0);
}