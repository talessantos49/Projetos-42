/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:36:29 by marvin            #+#    #+#             */
/*   Updated: 2023/04/03 19:34:44 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_ordenated(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi_push(argv[i]) > ft_atoi_push(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	check_max_min(char *str)
{
	const long long int	result = ft_atoi_push(str);

	if (result > 2147483647 || result < -2147483648)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	return (1);
}

int	check_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == 32)
		i++;
	if (str[i] == '\0')
		return (1);
	write(1, "Error\n", 7);
	return (0);
}

int	duplicated_args(int argc, char *argv[])
{
	int				i;
	int				k;
	long long int	*arguments;

	i = 1;
	arguments = (long long int *)ft_calloc(sizeof(int) * argc, argc);
	while (i < argc && arguments)
	{
		arguments[i] = ft_atoi_push (argv[i]);
		k = i;
		while (k != 1)
		{
			if (arguments[i] == arguments[k - 1])
			{
				write(1, "Error\n", 7);
				free(arguments);
				return (0);
			}
			k--;
		}
		i++;
	}
	free(arguments);
	return (1);
}

void	checkers(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_numbers(argv[i]) == 0)
			exit(0);
		if (check_max_min(argv[i]) == 0)
			exit(0);
		i++;
	}
	if (duplicated_args(argc, argv) == 0)
		exit(0);
	if (check_ordenated(argc, argv) == 0)
		exit(0);
}
